/*
Given an unsorted array nums, reorder it in-place such that nums[0] <= nums[1] >= nums[2] <= nums[3]....

For example, given nums = [3, 5, 2, 1, 6, 4], one possible answer is [1, 6, 2, 5, 3, 4].*/

// We only to consider local optimization , don't need to consider global optimization. the order in previous group will not affect the order of later group. 
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        if(nums.size() <= 1)
            return ;
        for(int i = 1; i < nums.size(); i+=2 )
        {
            if(nums[i-1] > nums[i])
                swap(nums[i-1], nums[i]);
            if(i + 1 < nums.size() and nums[i+1] > nums[i])
                swap(nums[i], nums[i+1]);
                
        }
        return ;
    }
};