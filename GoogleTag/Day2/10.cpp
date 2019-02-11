/*
813. Largest Sum of Averages
DescriptionHintsSubmissionsDiscussSolution
We partition a row of numbers A into at most K adjacent (non-empty) groups, then our score is the sum of the average of each group. What is the largest score we can achieve?

Note that our partition must use every number in A, and that scores are not necessarily integers.

Example:
Input: 
A = [9,1,2,3,9]
K = 3
Output: 20
Explanation: 
The best choice is to partition A into [9], [1, 2, 3], [9]. The answer is 9 + (1 + 2 + 3) / 3 + 9 = 20.
We could have also partitioned A into [9, 1], [2], [3, 9], for example.
That partition would lead to a score of 5 + 2 + 6 = 13, which is worse.
*/
class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        if(A.size() == 0)
            return 0;
        vector<int> prefix(A.size(), 0);
        prefix[0] = A[0];
        for(int i = 1;i < A.size();i++)
            prefix[i] = prefix[i-1] + A[i];
        vector<double> memo(A.size(), 0);
        for(int i = 0;i < A.size();i++)
            memo[i] = double(prefix[i]) / double(i + 1);
        for(int k = 2;k <= K;k++)
        {
            for(int i = A.size() - 1;i >= 0;i--)
            {
                for(int j = i;j >= 1;j--)
                {
                     double sum = prefix[i] - (j == 0 ? 0 : prefix[j-1]);
                     double size = i - j + 1;
                     memo[i] = max(memo[i],(sum / size) + memo[j-1]);
                }
            }
        }
        return memo[A.size()-1];
    }
};

class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        int n = A.size();
        vector<int> prefixSum(n + 1, 0);
        for(int i = 1; i <= n;i++)
        {
            prefixSum[i] = prefixSum[i-1] + A[i-1];
        }
        vector<double> dp(n, 0); 
        for(int i = 0;i < n;i++)
            dp[i] = double(prefixSum[n] - prefixSum[i]) / double(n - i); 
        for(int k = 2;k <= K;k++)
        {
            for(int i = 0;i < n;i++)
            {
                for(int j = i;j < n - 1;j++)
                {
                        dp[i] = max(dp[i], (double(prefixSum[j+1] - prefixSum[i]) / double(j - i + 1)) +  dp[j+1]);
                }
            }
        }
        return dp[0];
    }
};