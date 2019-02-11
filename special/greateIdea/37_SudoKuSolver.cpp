/*
37. Sudoku Solver
DescriptionHintsSubmissionsDiscussSolution
Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
Empty cells are indicated by the character '.'.


A sudoku puzzle...


...and its solution numbers marked in red.

Note:

The given board contain only digits 1-9 and the character '.'.
You may assume that the given Sudoku puzzle will have a single unique solution.
The given board size is always 9x9.
*/
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rowCheck(9);
        vector<unordered_set<char>> colCheck(9);
        vector<unordered_set<char>> blockCheck(9);
        int m = board.size();
        int n = m ? board[0].size() : 0;
        vector<pair<int,int>> needToFill;
        for(int i = 0;i < m;i++)
        {
            for(int j = 0;j < n;j++)
            {
                if(board[i][j] != '.')
                {
                    rowCheck[i].insert(board[i][j]);
                    colCheck[j].insert(board[i][j]);
                    blockCheck[CalBlockId(i,j)].insert(board[i][j]);
                }
                else 
                {
                    needToFill.push_back(make_pair(i,j));
                }
            }
        }
        Fill(board, rowCheck, colCheck,  blockCheck, needToFill, 0);
        

    }
    bool Fill(vector<vector<char>>& board, vector<unordered_set<char>>& rowCheck, vector<unordered_set<char>>& colCheck, vector<unordered_set<char>>& blockCheck, vector<pair<int,int>>& needToFill, int index)
    {
       if(index == needToFill.size())
            return true; 
       int row = needToFill[index].first;
       int col = needToFill[index].second; 
       int block = CalBlockId(row, col);
       for(int c = 1;c <= 9;c++)
       {
           int i = '0' + c; 
           if(rowCheck[row].count(i) == 0 && colCheck[col].count(i) == 0 && blockCheck[block].count(i) == 0)
           {
               rowCheck[row].insert(i); blockCheck[block].insert(i);colCheck[col].insert(i);
               if(Fill(board, rowCheck, colCheck, blockCheck, needToFill, index + 1)) 
               {
                  board[row][col] =  i; 
                  return true; 
               }
               rowCheck[row].erase(i); blockCheck[block].erase(i); colCheck[col].erase(i); 
           }
       } 
       return false; 
    }
    int CalBlockId(int row, int col)
    {
        return (row / 3) * 3 + (col / 3);
    }
};