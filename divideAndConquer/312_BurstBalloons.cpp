/*
Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums. You are asked to burst all the balloons. If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins. Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.

Find the maximum coins you can collect by bursting the balloons wisely.

Note: 
(1) You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
(2) 0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100

Example:

Given [3, 1, 5, 8]

Return 167

    nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
   coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167
Credits:
Special thanks to @dietpepsi for adding this problem and creating all test cases.
*/
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1); nums.insert(nums.end(), 1);
        int len = nums.size(); 
        vector<vector<int>> dp = vector<vector<int>>(len, vector<int>(len, 0));
        for(int l = 1;l <= len - 2;l++)
        {
            for(int i = 1;i <= len - 2 - l + 1;i++)
            {
                int start = i, end = start  + l - 1;
                for(int lastOne = start; lastOne <= end;lastOne++)
                {
                    dp[start][end] = max(dp[start][end], nums[start-1]*nums[lastOne]*nums[end + 1] + (lastOne != start ? dp[start][lastOne - 1] : 0) + (lastOne != end ? dp[lastOne + 1][end] : 0));
                }
            }
        }
        return dp[1][len-2];
    }
};