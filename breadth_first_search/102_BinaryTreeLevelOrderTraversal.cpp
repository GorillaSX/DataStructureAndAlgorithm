/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
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
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> results;
        if(root == NULL)
            return results;
        while(!q.empty())
        {
            int size = q.size();
            vector<int> cur;
            for(int i = 0;i < size;i++)
            {
                TreeNode* tmp = q.front();
                q.pop();
                cur.push_back(tmp->val);
                if(tmp->left != NULL)
                    q.push(tmp->left);
                if(tmp->right != NULL)
                    q.push(tmp->right);
            }
            results.push_back(cur);
        } 
        return results;
    }
};