/*
Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6].
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> results(n, 1);
        for(int i = 0;i < n - 1;i++)
        {
            results[i+1] = results[i] * nums[i];
        }
        int prod = 1;
        for(int i = n-1;i >= 0;i--)
        {
            results[i] = results[i] * prod;
            prod = prod * nums[i];
        }
        return results;
    }
};