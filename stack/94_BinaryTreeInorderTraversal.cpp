/*
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree [1,null,2,3],
   1
    \
     2
    /
   3
return [1,3,2].

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
    void pushIn(stack<TreeNode*>& roots, TreeNode* root)
    {
        while(root != NULL)
        {
            roots.push(root);
            root = root->left;
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> roots;
        pushIn(roots, root);
        vector<int> results;
        while(!roots.empty())
        {
            TreeNode* tmp = roots.top();
            roots.pop();
            results.push_back(tmp->val);
            pushIn(roots, tmp->right);
        }
        return results;
    }
};