/*
We are playing the Guess Game. The game is as follows:

I pick a number from 1 to n. You have to guess which number I picked.

Every time you guess wrong, I'll tell you whether the number I picked is higher or lower.

However, when you guess a particular number x, and you guess wrong, you pay $x. You win the game when you guess the number I picked.

Example:

n = 10, I pick 8.

First round:  You guess 5, I tell you that it's higher. You pay $5.
Second round: You guess 7, I tell you that it's higher. You pay $7.
Third round:  You guess 9, I tell you that it's lower. You pay $9.

Game over. 8 is the number I picked.

You end up paying $5 + $7 + $9 = $21.
Given a particular n ≥ 1, find out how much money you need to have to guarantee a win.
*/

class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for(int len = 2;len <= n;len++)
        {
            for(int i = 1;i <= n - len + 1;i++)
            {
                int start = i, end = i + len - 1;
                if(len == 2)
                    dp[start][end] = start;
                else if(len == 3)
                    dp[start][end] = start + 1;
                else
                {
                    int m = INT_MAX;
                    for(int pivot = start + 1; pivot < end; pivot++)
                    {
                        m = min(m, pivot + max(dp[start][pivot - 1], dp[pivot +1][end]));
                    }
                    dp[start][end] = m;
                }
            }
        }
        return dp[1][n];
    }
};