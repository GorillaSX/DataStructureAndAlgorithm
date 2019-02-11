/*
314. Binary Tree Vertical Order Traversal
DescriptionHintsSubmissionsDiscussSolution
Given a binary tree, return the vertical order traversal of its nodes' values. (ie, from top to bottom, column by column).

If two nodes are in the same row and column, the order should be from left to right.

Examples 1:

Input: [3,9,20,null,null,15,7]

   3
  /\
 /  \
 9  20
    /\
   /  \
  15   7 

Output:

[
  [9],
  [3,15],
  [20],
  [7]
]
Examples 2:

Input: [3,9,8,4,0,1,7]

     3
    /\
   /  \
   9   8
  /\  /\
 /  \/  \
 4  01   7 

Output:

[
  [4],
  [9],
  [3,0,1],
  [8],
  [7]
]
Examples 3:

Input: [3,9,8,4,0,1,7,null,null,null,2,5] (0's right child is 2 and 1's left child is 5)

     3
    /\
   /  \
   9   8
  /\  /\
 /  \/  \
 4  01   7
    /\
   /  \
   5   2

Output:

[
  [4],
  [9,5],
  [3,0,1],
  [8,2],
  [7]
]
Seen this question in a real interview before?  
Companies 

Related Topics 

Similar Questions 
Binary Tree Level Order Traversal
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution 
{
public: 
    vector<vector<int>> verticalOrder(TreeNode* root)
    {
        int leftMost = INT_MAX;
        int rightMost = INT_MIN;
        if(root == NULL)
            return vector<vector<int>>();
        traverse(root, 0, leftMost, rightMost);
        vector<vector<int>> result(rightMost - leftMost + 1, vector<int>());
        queue<pair<TreeNode*, int>> bfsq;
        bfsq.push(make_pair(root, -leftMost));
        while(!bfsq.empty())
        {
            int size = bfsq.size();
            for(int i = 0;i < size;i++)
            {
                auto cur = bfsq.front();
                bfsq.pop();
                result[cur.second].push_back(cur.first->val);
                if(cur.first->left != NULL)
                    bfsq.push(make_pair(cur.first->left, cur.second - 1));
                if(cur.first->right != NULL)
                    bfsq.push(make_pair(cur.first->right, cur.second + 1));
            }
        }
        return result;
    }
    void traverse(TreeNode* root, int post, int& leftMost, int & rightMost)
    {
        if(root == NULL)
            return;
        leftMost = min(leftMost, post);
        rightMost = max(rightMost, post);

        traverse(root->left, post - 1, leftMost, rightMost);
        traverse(root->right, post + 1, leftMost, rightMost);
    }
};