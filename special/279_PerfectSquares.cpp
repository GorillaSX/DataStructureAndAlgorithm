/*
Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
*/

//For those problems that need to find least steps, BFS is a kind of solution


//Slowest Solution, DFS with memory
class Solution {
public:
    int numSquares(int n) {
        unordered_map<int,int> memory;
        return leastNum(n, memory);
    }
    int leastNum(int n, unordered_map<int, int>& memory)
    {
        if(n < 4)
            return n;
        int largest = sqrt(n);
        int smallest = INT_MAX;
        for(int i = largest;i >= 1;i--)
        {
            
            int target = n - i * i;
            if(memory.count(target) != 0)
            {
                smallest = min(smallest, 1 + memory[target]);
            }
            else
            {
                smallest = min(smallest, 1 + leastNum(target, memory));
            }
        }
        memory[n] = smallest;
        return smallest;
    }
};


//DP Solution
class Solution {
public:
    int numSquares(int N) {
        vector<int> dp(N + 1, INT_MAX);
        dp[0] = 0;
        for(int n = 1; n <= N;n++)
        {
            int start = sqrt(n);
            for(int j = start;j >= 1;j--)
                dp[n] = min(dp[n], 1 +  dp[n - j * j]);
        }
        return dp[N];
        
    }
};

//BFS Solution
