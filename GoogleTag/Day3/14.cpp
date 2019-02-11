/*
Given a binary tree, return all duplicate subtrees. For each kind of duplicate subtrees, you only need to return the root node of any one of them.

Two trees are duplicate if they have the same structure with same node values.

Example 1: 
        1
       / \
      2   3
     /   / \
    4   2   4
       /
      4
The following are two duplicate subtrees:
      2
     /
    4
and
    4
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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> encodeStructure;
        unordered_map<int, vector<TreeNode*>> sameStructure;
        encodeStructure["#"] = 0;
        traverse(root, encodeStructure, sameStructure);
        vector<TreeNode*> result;
        for(auto ele : sameStructure)
        {
            if(ele.second.size() != 1)
                result.push_back(ele.second.back());
        }
        return result;
    }
    int traverse(TreeNode* root, unordered_map<string, int>& encodeStructure, unordered_map<int, vector<TreeNode*>>& sameStructure)
    {
        if(root == NULL)
            return 0;
        int leftId = traverse(root->left, encodeStructure, sameStructure);
        int rightId = traverse(root->right, encodeStructure, sameStructure);
        string structure = "(" + to_string(root->val) + "," + to_string(leftId) + "," +to_string(rightId) + ")";
        if(encodeStructure.count(structure) == 0)
        {
            encodeStructure[structure] = encodeStructure.size();
        }
        sameStructure[encodeStructure[structure]].push_back(root);
        return encodeStructure[structure];
    }
};