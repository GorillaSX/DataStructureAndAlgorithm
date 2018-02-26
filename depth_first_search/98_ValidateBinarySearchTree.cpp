/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
Example 1:
    2
   / \
  1   3
Binary tree [2,1,3], return true.
Example 2:
    1
   / \
  2   3
Binary tree [1,2,3], return false.
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
    bool isValidBST(TreeNode* root) 
    {
        TreeNode* prev = NULL;
        return traverse(root, prev);
    }

    bool traverse(TreeNode* root, TreeNode*& val)
    {
        if(root == NULL)
            return true;
        if(val == NULL && root->left == NULL)
        {
            val = root;
            return traverse(root->right, val);
        }
        if(root->left != NULL)
        {
            if(!traverse(root->left, val))
                return false;
        }
        if(root->val <= val->val)
            return false;
        val = root;
        return traverse(root->right, val);
    }
};