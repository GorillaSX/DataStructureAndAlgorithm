/*
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
*/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> checkBoard;
        for(int i = 0;i < board.size();i++)
        {
            for(int j = 0;j < board[i].size();j++)
            {
                int row = i + 10;
                int col = j + 20;
                int block = (i / 3) * 3 + (j / 3) + 30;
                if(board[i][j] != '.')
                {
                    auto rowr = checkBoard[row].insert(board[i][j]);
                    auto colr = checkBoard[col].insert(board[i][j]);
                    auto groupr = checkBoard[block].insert(board[i][j]);
                    if(rowr.second == false || colr.second == false || groupr.second == false)
                        return false;
                }
            }
        }
        return true;
    }
};