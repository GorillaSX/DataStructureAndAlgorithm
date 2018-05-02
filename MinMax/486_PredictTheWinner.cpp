/*
Given an array of scores that are non-negative integers. Player 1 picks one of the numbers from either end of the array followed by the player 2 and then player 1 and so on. Each time a player picks a number, that number will not be available for the next player. This continues until all the scores have been chosen. The player with the maximum score wins.

Given an array of scores, predict whether player 1 is the winner. You can assume each player plays to maximize his score.

Example 1:
Input: [1, 5, 2]
Output: False
Explanation: Initially, player 1 can choose between 1 and 2. 
If he chooses 2 (or 1), then player 2 can choose from 1 (or 2) and 5. If player 2 chooses 5, then player 1 will be left with 1 (or 2). 
So, final score of player 1 is 1 + 2 = 3, and player 2 is 5. 
Hence, player 1 will never be the winner and you need to return False.
Example 2:
Input: [1, 5, 233, 7]
Output: True
Explanation: Player 1 first chooses 1. Then player 2 have to choose between 5 and 7. No matter which number player 2 choose, player 1 can choose 233.
Finally, player 1 has more score (234) than player 2 (12), so you need to return True representing player1 can win.
Note:
1 <= length of the array <= 20.
Any scores in the given array are non-negative integers and will not exceed 10,000,000.
If the scores of both players are equal, then player 1 is still the winner.
*/
//O(2**n) time complexity
class Solution {
public:
    int MaximumScore(vector<int>& nums, int start, int end, vector<int>& sums)
    {
        if(start == end)
            return nums[start];
        else if(end - start == 1)
            return max(nums[start], nums[end]);
        else 
        {
            return max(nums[start] + sums[end] - sums[start] - MaximumScore(nums, start + 1, end, sums), nums[end] + sums[end-1] - (start == 0? 0 :sums[start - 1]) - MaximumScore(nums, start, end - 1, sums));
        }
    }
    bool PredictTheWinner(vector<int>& nums) {
       if(nums.size() == 1)
            return true;
       vector<int> sums(nums.size(), 0);
       sums[0] = nums[0];
       for(int i = 1;i < sums.size() ;i++)
       {
           sums[i] = nums[i] + sums[i-1];
       } 
       int player1 = MaximumScore(nums, 0, nums.size() - 1, sums);
       int player2 = sums[nums.size() - 1] - player1;
       if(player1 >= player2)
       {
            return true;
       }
        
       return false;
    }
};

// n**2 
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
       if(nums.size() == 1)
            return true;
       vector<int> sums(nums.size(), 0);
       sums[0] = nums[0];
       for(int i = 1;i < sums.size() ;i++)
       {
           sums[i] = nums[i] + sums[i-1];
       } 
       vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), 0));
       for(int len = 1;len <= nums.size(); len++)
       {
           for(int i = 0;i < nums.size() - len + 1;i++)
           {
               int start = i, end = start + len - 1;
               if(start == end)
                   dp[start][end] = nums[start];
               else if(end - start == 1)
                   dp[start][end] = max(nums[start], nums[end]);
               else 
               {
                   dp[start][end] = max(nums[start] + sums[end] - sums[start] - dp[start + 1][end], nums[end] + sums[end-1] - (start == 0 ? 0 : sums[start - 1]) - dp[start][end - 1]);
               }
           }
       }
       int player1 = dp[0][nums.size()-1];
        cout << player1 << endl;
       int player2 = sums[nums.size() - 1] - player1;
       if(player1 >= player2)
            return true;
       return false;
    }
};