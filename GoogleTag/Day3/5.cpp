/*
uares
DescriptionHintsSubmissionsDiscussSolution
Given a positi279. Perfect Sqve integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

Example 1:

Input: n = 12
Output: 3 
Explanation: 12 = 4 + 4 + 4.
Example 2:

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.
*/

class Solution 
{
public:
    int sumSquares(int N)
    {
        vector<int> dp(N+1, INT_MAX);
        dp[0] = 0;
        for(int n = 1;n <= N;n++)
        {
            int start = sqrt(n);
            for(int j = start;j >= 1;j--)
                dp[n] = min(dp[n], 1 + dp[n - j * j]);
        }
        return dp[N];
    }
};