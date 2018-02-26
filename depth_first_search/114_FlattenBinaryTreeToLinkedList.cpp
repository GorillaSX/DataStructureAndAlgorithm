/*
Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
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
    TreeNode* Find(TreeNode* root)
    {
        while(root->right != NULL)
        {
            root = root->right;
        }
        return root;
    }
    void flatten(TreeNode* root) {
        while(root != NULL)
        {
            if(root->left != NULL)
            {
                TreeNode* leftest = Find(root->left);
                leftest->right = root->right;
                root->right = root->left;
                root->left = NULL;
            }
            root = root->right;
        }
    }
};