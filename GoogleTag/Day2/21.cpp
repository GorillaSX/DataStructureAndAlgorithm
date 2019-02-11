/*
549. Binary Tree Longest Consecutive Sequence II
DescriptionHintsSubmissionsDiscussSolution
Given a binary tree, you need to find the length of Longest Consecutive Path in Binary Tree.

Especially, this path can be either increasing or decreasing. For example, [1,2,3,4] and [4,3,2,1] are both considered valid, but the path [1,2,4,3] is not valid. On the other hand, the path can be in the child-Parent-child order, where not necessarily be parent-child order.

Example 1:
Input:
        1
       / \
      2   3
Output: 2
Explanation: The longest consecutive path is [1, 2] or [2, 1].
Example 2:
Input:
        2
       / \
      1   3
Output: 3
Explanation: The longest consecutive path is [1, 2, 3] or [3, 2, 1].
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
    int longestConsecutive(TreeNode* root) {
        int longest = 0;
        longestPath(root, longest);
        return longest;
    }
    pair<int,int> longestPath(TreeNode* root, int& longest)
    {
        if(root == NULL)
            return make_pair(0,0);
        pair<int,int> leftR  = longestPath(root->left, longest);
        pair<int,int> rightR = longestPath(root->right, longest);
        int incp = 1, decp = 1, inc = 1, dec = 1;
        if(root->left != NULL && root->val - root->left->val == 1)
        {
            inc = max(1, 1 + leftR.first);
            incp = 1 + leftR.first;
        }
        else if(root->left != NULL && root->val - root->left->val == -1)
        {
            dec = max(1, 1 + leftR.second);
            decp = 1 + leftR.second;
        }

        if(root->right != NULL && root->val - root->right->val == 1)
        {
            inc = max(inc, 1 + rightR.first);
            decp = decp + rightR.first;
        }
        else if(root->right != NULL && root->val - root->right->val == -1)
        {
            dec = max(dec, 1 + rightR.second);
            incp = incp + rightR.second;

        }
        longest = max(longest, max(incp, decp));
        return make_pair(inc, dec); 
    }
};