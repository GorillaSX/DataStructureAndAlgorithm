/*
Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7
*/
//Solution one
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() == 0)
            return NULL;
        for(int i = 0;i < inorder.size();i++)
        {
            if(inorder[i] == postorder[postorder.size()-1])
            {
                vector<int> inorderleft(inorder.begin(), inorder.begin() + i);
                vector<int> postorderleft(postorder.begin(), postorder.begin() + i);
                TreeNode* root = new TreeNode(inorder[i]);
                root->left = buildTree(inorderleft, postorderleft);
                vector<int> inorderright(inorder.begin()+i+1, inorder.end());
                vector<int> postorderright(postorder.begin() + i, postorder.end() - 1);
                root->right = buildTree(inorderright, postorderright);
                return root;
            }
        }
    }
};

//Solution two
