/*
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
class Solution {
public:
    int longestConsecutive(TreeNode* root) {
        int result = 0;
        findPath(root, result);
        return result ;
    }
    
    pair<int,int> findPath(TreeNode* root, int& result)
    {
        if(root == NULL)
            return make_pair(0,0);
        pair<int, int> left = findPath(root->left, result);
        pair<int, int> right= findPath(root->right, result);
        int pathlen = 1;
        if(root->left != NULL and root->val - root->left->val == 1)
            pathlen += left.first;
        if(root->right != NULL and root->right->val - root->val == 1)
            pathlen += right.second;
        result = max(result, pathlen);
        pathlen  = 1;
        if(root->left != NULL and root->left->val - root->val == 1)
            pathlen += left.second;
        if(root->right != NULL and root->val - root->right->val == 1)
            pathlen += right.first;
        result = max(result, pathlen);
        int ascending = 1, descending = 1;
        if(root->left != NULL and root->val - root->left->val == 1)
            ascending = max(ascending, 1 + left.first);
        if(root->right != NULL and root->val - root->right->val == 1)
            ascending = max(ascending, 1 + right.first);
        if(root->left != NULL and root->val - root->left->val == -1)
            descending = max(descending, 1 + left.second);
        if(root->right != NULL and root->val - root->right->val == -1)
            descending = max(descending, 1 + right.second);
        result = max(ascending, result);
        result = max(descending, result);
        return make_pair(ascending, descending);
    }
};