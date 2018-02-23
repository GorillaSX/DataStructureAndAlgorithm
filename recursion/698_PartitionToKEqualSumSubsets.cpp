/*
Given an array of integers nums and a positive integer k, find whether it's possible to divide this array into k non-empty subsets whose sums are all equal.

Example 1:
Input: nums = [4, 3, 2, 3, 5, 2, 1], k = 4
Output: True
Explanation: It's possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.
*/

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
       int sum = accumulate(nums.begin(), nums.end(), 0);
       if(sum % k != 0)
        return false;
       int target = sum / k;
       sort(nums.begin(), nums.end());
       vector<int> group(k, 0);
       return search(group, nums, nums.size()-1, k, target);


    }
    bool search(vector<int>& group, vector<int>& nums, int index, int k, int target)
    {
        if(index < 0)
            return true;
        for(int i = 0;i < group.size();i++)
        {
            if(group[i] + nums[index] <= target)
            {
                group[i] += nums[index];
                if(search(group, nums, index - 1, k, target))
                    return true;
                else
                    group[i] -= nums[index];
            }
        }
        return false;
    }
};