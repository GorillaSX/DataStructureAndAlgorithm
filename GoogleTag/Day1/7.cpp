/*
Given an Android 3x3 key lock screen and two integers m and n, where 1 ≤ m ≤ n ≤ 9, count the total number of unlock patterns of the Android lock screen, which consist of minimum of m keys and maximum n keys.

Rules for a valid pattern:
Each pattern must connect at least m keys and at most n keys.
All the keys must be distinct.
If the line connecting two consecutive keys in the pattern passes through any other keys, the other keys must have previously selected in the pattern. No jumps through non selected key is allowed.
The order of keys used matters.

Explanation:
| 1 | 2 | 3 |
| 4 | 5 | 6 |
| 7 | 8 | 9 |
Invalid move: 4 - 1 - 3 - 6 
Line 1 - 3 passes through key 2 which had not been selected in the pattern.

Invalid move: 4 - 1 - 9 - 2
Line 1 - 9 passes through key 5 which had not been selected in the pattern.

Valid move: 2 - 4 - 1 - 3 - 6
Line 1 - 3 is valid because it passes through key 2, which had been selected in the pattern

Valid move: 6 - 5 - 4 - 1 - 9 - 2
Line 1 - 9 is valid because it passes through key 5, which had been selected in the pattern.

Example:
Given m = 1, n = 1, return 9.
*/

class Solution {
public:
    int numberOfPatterns(int m, int n) {
        vector<vector<bool> visited(3, vector<bool>(3, false));
        int count = 0;
        for(int i = 0;i < 3;i++)
        {
            for(int j = 0;j < 3;j++)
            {
                visited[i][j] = true;
                backtracking(visited, m, n, 1, i, j, count);
                visited[i][j] = false;
            }
        }
        return count;
    }
    void backtracking(vector<vector<int>>& visited, int m, int n, int curStep, int curRow, int curCol, int& count)
    {
        if(curStep >= m)
        {
            count++;
        }
        if(curStep == n)
            return ;
        for(int i = 0;i < 3;i++)
        {
            for(int j = 0;j < 3;j++)
            {
                if(visited[i][j] == false)
                {
                    int distance = abs(curRow - i) * abs(curRow - i) + abs(curCol - j) * abs(curCol - j);
                    if((distance % 4  == 0 && visited[(row + i)/2][(col +j) / 2] == true) or distance % 4 != 0)
                    {
                        visited[i][j] = true;
                        backtracking(visited, m, n, curStep + 1, i, j, count);
                        visited[i][j] = false;
                    }

                }
            }
        }
    }
};



