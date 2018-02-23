/*
Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree [1,null,2,3],
   1
    \
     2
    /
   3
return [1,2,3].

Note: Recursive solution is trivial, could you do it iteratively?
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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> roots;
        vector<int> results;
        roots.push(root);
        while(!roots.empty())
        {
            TreeNode* tmp = roots.top();
            roots.pop();
            if(tmp != NULL)
            {
                results.push_back(tmp->val);
                roots.push(tmp->right);
                roots.push(tmp->left);
            }
        }
        return results;
    }
};