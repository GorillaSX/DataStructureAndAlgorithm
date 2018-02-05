/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note: The solution set must not contain duplicate triplets.

For example, given array S = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]

*/
//
class Solution 
{
    public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> results;
        if(nums.size() < 3)
            return results;
        for(int i = 0;i < nums.size()-2;i++)
        {
            if(i != 0 && nums[i] == nums[i-1])
                continue;
            int target = 0 - nums[i];
            int left = i + 1;
            int right = nums.size() - 1;
            while(left < right)
            {
                if(nums[left] + nums[right] == target)
                {
                    vector<int> res = {nums[i], nums[left], nums[right]};
                    results.push_back(res);
                    do{left++;}while(left < nums.size() &&  nums[left] == nums[left-1]);
                    
                    do{right--;}while(right > 0  &&  nums[right] == nums[right+1]);
                    
                }
                else if(nums[left] + nums[right] < target)
                {
                    left++;
                    while(left < nums.size()   && nums[left] == nums[left-1])
                        left++;
                }
                else if(nums[left] + nums[right] > target)
                {
                    right--;
                    while(right > 0  && nums[right] == nums[right + 1])
                        right--;
                }
            }
        }
        return results;
    }
};
