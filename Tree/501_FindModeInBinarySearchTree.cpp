/*Given a binary search tree (BST) with duplicates, find all the mode(s) (the most frequently occurred element) in the given BST.

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than or equal to the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
For example:
Given BST [1,null,2,2],
   1
    \
     2
    /
   2
return [2].

Note: If a tree has more than one mode, you can return them in any order.

Follow up: Could you do that without using any extra space? (Assume that the implicit stack space incurred due to recursion does not count).
*/

class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> result;
        if(root == NULL)
            return result;
        bool start = true;
        int last = 0, times = 0, maxTimes = 0;
        inorder(root, start, last, times, maxTimes, result);
        if(times > maxTimes)
            result.clear();
        if(times >= maxTimes)
            result.push_back(last);
        return result;
        
    }
    void inorder(TreeNode* root, bool& start, int& last, int& times, int& maxTimes, vector<int>& result)
    {
        if(root == NULL)
            return ;
        inorder(root->left, start, last, times, maxTimes, result);
        if(start == true)
        {
            start  = false;
            last = root->val;
            times = 1; 
        }
        else
        {
            if(root->val == last)
                times++;
            else
            {
                if(times == maxTimes)
                {
                    result.push_back(last);
                }
                else if(times > maxTimes)
                {
                    result.clear();
                    maxTimes = times;
                    result.push_back(last);
                }
                times = 1;
                last = root->val;
            }
        }
        inorder(root->right, start, last, times, maxTimes, result);
    }
    
};