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
Therefore, you need to return above trees' root in the form of a list.
*/
//Brute Force TLE
class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<int, vector<TreeNode*>> maps;
        traverse(root, maps);
        vector<TreeNode*> results;
        for(auto ele: maps)
        {
            unordered_set<TreeNode*> sets;
            for(int i = 0;i < ele.second.size() - 1;i++)
            {
                if(sets.count(ele.second[i]) == 0)
                {
                    bool findDup = false;
                    for(int j = i + 1;j < ele.second.size();j++)
                    {
                        if(sets.count(ele.second[j]) == 0)
                        {
                            if(checkSame(ele.second[i], ele.second[j]))
                            {
                                if(findDup == false)
                                {
                                    results.push_back(ele.second[i]);
                                    findDup = true;
                                }
                                sets.insert(ele.second[j]);
                            }
                        }
                    }
                }
            }
        }
        return results;
        
    }
    void traverse(TreeNode* root, unordered_map<int, vector<TreeNode*>>& maps)
    {
        if(root == NULL)
            return ;
        maps[root->val].push_back(root);
        traverse(root->left, maps);
        traverse(root->right, maps);
    }
    bool checkSame(TreeNode* nodea, TreeNode* nodeb)
    {
        if(nodea == NULL and nodeb == NULL)
            return true;
        else if((nodea == NULL and nodeb != NULL) or ( nodea != NULL and nodeb == NULL))
            return false;
        if(!checkSame(nodea->left, nodeb->left))
            return false;
        if(nodea->val != nodeb->val)
            return false;
        return checkSame(nodea->right, nodeb->right);
    }
};

//Second, 
class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, vector<TreeNode*>> maps;
        unordered_map<string, int> idcode;
        traverse(root, maps, idcode);
        vector<TreeNode*> result;
        for(auto ele : maps)
        {
            if(ele.second.size() != 1)
                result.push_back(ele.second.back());
        }
        return result;
    }
    int traverse(TreeNode* root, unordered_map<string, vector<TreeNode*>>& maps, unordered_map<string, int>& idcode)
    {
        if(root == NULL)
            return 0;
        int left = traverse(root->left, maps, idcode);
        int right = traverse(root->right, maps, idcode);
        string noderep = to_string(root->val) + "," + to_string(left) + "," + to_string(right);
        if(idcode.count(noderep) == 0)
        {
            int id = idcode.size() + 1;
            idcode[noderep] = id;
        }   
        maps[noderep].push_back(root);
        
        return idcode[noderep];
    }
};