/*
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

For example:
Given the following binary tree,
   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
You should return [1, 3, 4].

Credits:
Special thanks to @amrsaqr for adding this problem and creating all test cases.

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

//Solution one: 4ms Recursion
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> results;
        if(root == NULL)
            return results;
        update(results, root, 0);
        return results;
    }
    void update(vector<int>& results, TreeNode* node, int level)
    {
        if(node == NULL)
            return ;
        if(results.size() == level)
        {
            results.push_back(node->val);
        } 
        results[level] = node->val;
        update(results, node->left, level + 1);
        update(results, node->right, level + 1);
    }

};
//Solution Two: BFS 4ms;
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> results;
        if(root == NULL)
            return results;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            for(int i = 0;i < size; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                if(i == size - 1)
                    results.push_back(node->val);
                if(node->left != NULL)
                    q.push(node->left);
                if(node->right != NULL)
                    q.push(node->right);
            }
        }
        return results;
    }
};