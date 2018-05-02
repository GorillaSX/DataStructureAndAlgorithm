/*
On an infinite number line (x-axis), we drop given squares in the order they are given.

The i-th square dropped (positions[i] = (left, side_length)) is a square with the left-most point being positions[i][0] and sidelength positions[i][1].

The square is dropped with the bottom edge parallel to the number line, and from a higher height than all currently landed squares. We wait for each square to stick before dropping the next.

The squares are infinitely sticky on their bottom edge, and will remain fixed to any positive length surface they touch (either the number line or another square). Squares dropped adjacent to each other will not stick together prematurely.


Return a list ans of heights. Each height ans[i] represents the current highest height of any square we have dropped, after dropping squares represented by positions[0], positions[1], ..., positions[i].

Example 1:
Input: [[1, 2], [2, 3], [6, 1]]
Output: [2, 5, 5]
Explanation:

After the first drop of positions[0] = [1, 2]:
_aa
_aa
-------
The maximum height of any square is 2.


After the second drop of positions[1] = [2, 3]:
__aaa
__aaa
__aaa
_aa__
_aa__
--------------
The maximum height of any square is 5.  
The larger square stays on top of the smaller square despite where its center
of gravity is, because squares are infinitely sticky on their bottom edge.


After the third drop of positions[1] = [6, 1]:
__aaa
__aaa
__aaa
_aa
_aa___a
--------------
The maximum height of any square is still 5.

Thus, we return an answer of [2, 5, 5].


Example 2:
Input: [[100, 100], [200, 100]]
Output: [100, 100]
Explanation: Adjacent squares don't get stuck prematurely - only their bottom edge can stick to surf
*/

struct STNode 
{
    int start, end, count;
    STNode *left, *right;
    STNode(int s, int e, int c = 0):start(s), end(e), left(NULL), count(c), right(NULL){}
    int query(STNode* root)
    {
        if(root == NULL)
            return 0;
        else if(start > root->end)
            return this->query(root->right);
        else if(end < root->start)
            return this->query(root->left);
        else 
        {
            int leftreturn = 0, rightreturn = 0;
            if(start < root->start)
            {
                STNode node(start, root->start - 1);
                leftreturn = node.query(root->left);
            }
            if(end > root->end)
            {
                STNode node(root->end + 1, end);
                rightreturn = node.query(root->right);
            }
            return max(leftreturn, max(rightreturn, root->count));
        }
    }

    void update(STNode*& root)
    {
        if(root == NULL)
            root = this;
        else if(start > root->end)
            return this->update(root->right);
        else if(end < root->start)
            return this->update(root->left);
        else 
        {
            if(start < root->start)
            {
                STNode* node = new STNode(start, root->start - 1, count);
                cout << node->count << endl;
                node->update(root->left);
            }
                if(end < root->end)
                {
                    STNode* newright = new STNode(end + 1, root->end, root->count);
                    newright->right = root->right;
                    root->right = newright;
                    root->end = end;
                }
            if(end > root->end)
            {
                STNode* node  = new STNode(root->end + 1, end, count);
                node->update(root->right);
            }                
                if(start > root->start)
                {
                    STNode* newleft = new STNode(root->start, start - 1, root->count);
                    newleft->left = root->left;
                    root->left = newleft;
                    root->start = start;
                }
            root->count = count;
        }
    }
};
class Solution {
public:
    vector<int> fallingSquares(vector<pair<int, int>>& positions) {
        vector<int> results;
        int curHeight = 0;
        STNode* root = NULL;
        for(auto p : positions)
        {
            STNode* node = new STNode(p.first, p.first + p.second - 1);
            int height = node->query(root);
            cout << height << endl;
            curHeight = max(curHeight, height + p.second);
            node->count = height + p.second;
            node->update(root);
            results.push_back(curHeight);
        }
        return results;
    }
};