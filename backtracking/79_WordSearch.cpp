/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
*/

class Solution 
{
    public:
    bool exist(vector<vector<char>>& board, string word)
    {
        int m =board.size();
        int n = m != 0 ? board[0].size() : 0;
        vector<vector<bool>> visited = vector<vector<bool>>(m, vector<bool>(n, false));
        for(int i = 0;i < m;i++)
        {
            for(int j = 0;j < n;j++)
            {
                if(board[i][j] == word[0])
                {
                   visited[i][j] = true;
                   if(deepIn(board,  visited, word, i, j , 1))
                        return true; 
                    visited[i][j] = false;
                }
            }
        }
        return false;
    }

    bool deepIn(vector<vector<char>>& board, vector<vector<bool>>& visited, string word, int row, int col, int index)
    {
        int m = board.size();
        int n = m != 0 ? board[0].size() : 0;
        if(index == word.size())
            return true;
        int delta[5] = {0, 1, 0, -1, 0};
        for(int i = 0;i < 4;i++)
        {
            int r = row + delta[i];
            int c = col + delta[i+1];
            if(r >= 0 && r < m && col >= 0 && col < n && board[r][c] == word[index] && visited[r][c] == false )
            {
                visited[r][c] = true;
                if(deepIn(board,  visited, word, r, c, index + 1))
                    return true;
                visited[r][c] = false;
            }
        }
        return false;

    }
};