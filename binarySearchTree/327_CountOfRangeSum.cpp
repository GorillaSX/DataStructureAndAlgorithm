/*
Given an integer array nums, return the number of range sums that lie in [lower, upper] inclusive.
Range sum S(i, j) is defined as the sum of the elements in nums between indices i and j (i ≤ j), inclusive.

Note:
A naive algorithm of O(n2) is trivial. You MUST do better than that.

Example:
Given nums = [-2, 5, -1], lower = -2, upper = 2,
Return 3.
The three ranges are : [0, 0], [2, 2], [0, 2] and their respective sums are: -2, -1, 2.
*/
class TNode
{
    public:
        TNode* left, *right;
        long long val, numberOfNodesLeftSide, selfCount;
        TNode(long long v):val(v), selfCount(1), numberOfNodesLeftSide(0), left(NULL), right(NULL){}
};
int insert(TNode* root, long long val, int curNum)
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
int find(TNode* root, long long val, int curNum)
{
    if(root == NULL)
        return curNum;
    if(val == root->val)
    {
        return curNum + root->numberOfNodesLeftSide + root->selfCount;
    }
    else if(val < root->val)
    {
        return find(root->left, val, curNum);
    }
    else if(val > root->val)
    {
        return find(root->right, val, curNum + root->numberOfNodesLeftSide + root->selfCount);
    }
}
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
       if(nums.size() == 0)
            return 0;
       vector<long long> sums(nums.size() + 1, 0);
       for(int i = 1;i < sums.size();i++)
       {
           sums[i] = sums[i-1] + nums[i-1]; 
       }
       int count = 0;
       TNode* root = NULL;
       for(int i = 1;i < sums.size();i++) 
       {
          if(sums[i] >= lower && sums[i] <= upper)
            count++;
           if(root != NULL)
           {
            long long right = sums[i] - lower;
            long long left =  sums[i] - upper;
            count = count + find(root, right, 0) - find(root, left - 1, 0);
            insert(root, sums[i], 0);
           }
           else
           {
               root = new TNode(sums[i]);
           }
       }
       return count;
    }
};