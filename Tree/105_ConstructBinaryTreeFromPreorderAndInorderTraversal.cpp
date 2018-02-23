/*
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0)
            return NULL;
        TreeNode* root = new TreeNode(preorder[0]);
        if(preorder.size() == 1)
        {
            return root;
        }
        else
        {
            for(int i = 0;i < inorder.size();i++)
            {
                if(inorder[i] == preorder[0])
                {
                    if(i > 0)
                    {
                    vector<int> p(preorder.begin() + 1, preorder.begin()  + 1 + i);
                    vector<int> q(inorder.begin(), inorder.begin() + i);
                    root->left = buildTree(p,q);
                    }
                    if(i < inorder.size()-1)
                    {
                    vector<int> pr(preorder.begin() + 1 + i, preorder.end());
                    vector<int> qr(inorder.begin() + i + 1, inorder.end());
                    root->right =  buildTree(pr,qr);
                    }
                    return root;
                }
            }    
        }
    }
};