/*
According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies, as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population..
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
Write a function to compute the next state (after one update) of the board given its current state.

Follow up: 
Could you solve it in-place? Remember that the board needs to be updated at the same time: You cannot update some cells first and then use their updated values to update other cells.
In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches the border of the array. How would you address these problems?
Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
*/
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = m != 0 ? board[0].size() : 0;
        if(m == 0)
            return ;
        int delta[16] = {0, 1, 0, -1, 1, 0, -1, 0, -1, -1, -1, 1, 1, 1, 1, -1};
        for(int i = 0;i < m;i++)
        {
            for(int j = 0;j < n;j++)
            {
                int count = 0;
                for(int step = 0;step <= 14; step+= 2)
                {
                    int row = i + delta[step];
                    int col = j + delta[step + 1];
                    if(row >= 0 && row < m && col >= 0 && col < n)
                    {
                        if(board[row][col] & 1 == 1)
                            count++;
                    }
                }
                int state = board[i][j] & 1;
                if(state == 1 && (count == 2 || count == 3))
                    board[i][j] |= 2;
                else if(state == 0 && count == 3)
                    board[i][j] |= 2;
            }
            if(i > 0)
            {
                for(int j = 0;j < n;j++)
                    board[i - 1][j] = (board[i-1][j] >> 1) & 1;
            }
        }
        for(int j = 0;j < n;j++)
        {
            board[m-1][j] = (board[m-1][j] >> 1) & 1;
        }
    }
};