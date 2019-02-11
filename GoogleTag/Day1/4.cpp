/*
494. Target Sum
DescriptionHintsSubmissionsDiscussSolution
You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.

Find out how many ways to assign symbols to make sum of integers equal to target S.

Example 1:
Input: nums is [1, 1, 1, 1, 1], S is 3. 
Output: 5
Explanation: 

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

There are 5 ways to assign symbols to make the sum of nums be target 3.
Note:
The length of the given array is positive and will not exceed 20.
The sum of elements in the given array will not exceed 1000.
Your output answer is guaranteed to be fitted in a 32-bit integer.
*/

//
class Solution 
{
    public:
    int findTargetSumWays(vector<int>& nums, int s)
    {
        int result = 0;
        TryAllPossible(nums, s, 0, 0, count);
        return result;

    }
    void TryAllPossible(vector<int>& nums, int s, int curSum , int index, int & count)
    {
        if(index == nums.size() && curSum == s)
        {
            count++;
            return; 
        }
        TryAllPossible(nums, s, curSum + nums[index], index + 1, count);
        TryAllPossible(nums, s, curSum - nums[index], index + 1, count);
    }
};
//Dynamic Programming 
class Solution 
{
public:
    int findTargetSumWays(vector<int>& nums, int s)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        return (sum < s || ( (s + sum) % 2 != 0 ) ? 0 : subsetSum(nums, (s + sum) >> 1));
    }
    int subsetSum(vector<int>& nums, int s)
    {
        vector<vector<int>> memory(nums.size() + 1, vector<int>(s + 1, 0));
        for(int i = 0;i <= nums.size();i++)
            memory[i][0] = 1; 
        for(int i = 1;i <= nums.size();i++)
        {
            for(int j = 0;j <= s;j++)
            {
                memory[i][j] = memory[i-1][j];
                if(j >= nums[i-1])
                {
                    memory[i][j] += memory[i-1][j - nums[i-1]];
                }
            }
        }
        return memory[nums.size()][s];
    }
};