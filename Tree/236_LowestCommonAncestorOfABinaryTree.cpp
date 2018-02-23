/*
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”

        _______3______
       /              \
    ___5__          ___1__
   /      \        /      \
   6      _2       0       8
         /  \
         7   4
For example, the lowest common ancestor (LCA) of nodes 5 and 1 is 3. Another example is LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
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
    bool FindNode(TreeNode* root, TreeNode* node, stack<TreeNode*>& ancestor)
    {
        if(root == NULL)
            return false;
        if(root == node)
        {
            ancestor.push(root);
            return true;
        }
        else
        {
            if(FindNode(root->left, node, ancestor))
            {
                ancestor.push(root);
                return true;
            }
            if(FindNode(root->right, node, ancestor))
            {
                ancestor.push(root);
                return true;
            }
            return false;
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<TreeNode*> pA;
        stack<TreeNode*> qA;
        FindNode(root, p, pA);
        FindNode(root, q, qA);
        TreeNode* res = NULL;
        while(!pA.empty() && !qA.empty())
        {
           if(pA.top() != qA.top())
                return res; 
           else
           {
               res = pA.top();
               pA.pop();
               qA.pop(); 
           } 
        }
        return res;
    }
};