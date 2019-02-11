/*
240. Search a 2D Matrix II
DescriptionHintsSubmissionsDiscussSolution
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
Example:

Consider the following matrix:

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
Given target = 5, return true.

Given target = 20, return false.
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = m ? matrix[0].size() : 0;
        int r = 0, c = n - 1;
        while(r < m && c >= 0)
        {
            if(target == matrix[r][c])
                return true;
            else if(target > matrix[r][c])
                r++;
            else if(target < matrix[r][c])
                c--;
        }
        return false;
    }
};

class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        if(matrix.size() == 0)
            return false;
        if(matrix[0].size() == 0)
            return false;
        int left = 0, top = 0, bot = matrix.size() - 1, right = matrix[0].size() - 1;
        return search(matrix, target, left, right, top, bot);
    }
    bool search(vector<vector<int> >& matrix, int target, int left, int right, int top, int bot)
    {
        if(left == right)
            return searchCol(matrix, target, left, top, bot);
        else if(top == bot)
            return searchRow(matrix, target, top, left, right);
        else if(left == right && top == bot)
            return matrix[left][top] == target;
        else 
        {
            int rm = (top + bot) / 2;
            int cm = (left + right) / 2;
            if(target >= matrix[top][left] && matrix[rm][cm] >= target)
            {
                if(search(matrix, target, left, cm, top, rm))
                    return true;
            }
            if(target >= matrix[top][cm+1] && matrix[rm][right] >= target)
            {
                if(search(matrix, target, cm + 1, right, top, rm))
                   return true;
            }
            if(target >= matrix[rm+1][left] && matrix[bot][cm] >= target)
            {
                if(search(matrix, target, left, cm, rm + 1, bot))
                    return true;
            }
            if(target >= matrix[rm+1][cm+1] && matrix[bot][right] >= target)
            {
                if(search(matrix, target, cm + 1, right, rm + 1, bot))
                    return true;
            }
            return false;
        }
    }
    bool searchRow(vector<vector<int> >& matrix, int target, int row, int left, int right)
    {
        if(left == right)
        {
            if(matrix[row][left] == target)
                return true;
            else 
                return false;
        }
        else 
        {
            int mid = (left + right) / 2;
            if(matrix[row][mid] >= target)
                return searchRow(matrix, target, row, left, mid);
            else 
                return searchRow(matrix, target, row, mid + 1, right);
        }
    }
    bool searchCol(vector<vector<int> >& matrix, int target, int col, int top, int bot)
    {
        if(top == bot)
        {
            if(matrix[top][col] == target)
                return true;
            else 
                return false;
        }
        else 
        {
            int mid = (top + bot)  / 2;
            if(matrix[mid][col] >= target)
                return searchCol(matrix, target, col, top, mid);
            else 
                return searchCol(matrix, target, col, mid + 1, bot);
        }
    }
};