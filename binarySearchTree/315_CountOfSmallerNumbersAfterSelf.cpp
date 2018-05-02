/*
You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].

Example:

Given nums = [5, 2, 6, 1]

To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.
Return the array [2, 1, 1, 0].
*/
class TNode
{
    public:
        TNode* left, *right;
        int val, numberOfNodesLeftSide, selfCount;
        TNode(int v):val(v), selfCount(1), numberOfNodesLeftSide(0), left(NULL), right(NULL){}
};
int insert(TNode* root, int val, int curNum)
{
    if(val == root->val)
    {
        root->selfCount++;
        return root->numberOfNodesLeftSide + curNum;
    }
    else if(val > root->val)
    {
        if(root->right == NULL)
        {
            TNode* r = new TNode(val);
            root->right = r;
            return curNum + root->numberOfNodesLeftSide + root->selfCount;
        }
        else
        {
            return insert(root->right, val, curNum + root->numberOfNodesLeftSide + root->selfCount);
        }
    }
    else if(val < root->val)
    {
        root->numberOfNodesLeftSide++;
        if(root->left == NULL)
        {
            TNode* l = new TNode(val);
            root->left = l;
            return curNum;
        }
        else 
        {
            return insert(root->left, val, curNum);
        }
    }
}
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> results(nums.size(), 0);
        if(nums.size() <= 1)
            return results;
        TNode* root = new TNode(nums.back());
        for(int i = nums.size() - 2;i >= 0;i--)
        {
            results[i] = insert(root, nums[i], 0);
        }
        return results;
    }
};