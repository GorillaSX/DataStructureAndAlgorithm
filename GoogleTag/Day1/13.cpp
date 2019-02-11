/*
498. Diagonal Traverse
DescriptionHintsSubmissionsDiscussSolution
Given a matrix of M x N elements (M rows, N columns), return all elements of the matrix in diagonal order as shown in the below image.

Example:
Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output:  [1,2,4,7,5,3,6,8,9]
Explanation:

Note:
The total number of elements of the given matrix will not exceed 10,000.
*/
class Solution {
public:
    void GenerateSequence(vector<vector<int>>& matrix, int row, int col, bool reverse, vector<int>& result)
    {
        if(!reverse)
        {
            while(row < matrix.size() && col >= 0)
            {
                result.push_back(matrix[row][col]);
                row++;
                col--;
            }
        }
        else 
        {
            if(matrix.size() - row <= col + 1)
            {
                col = col - (matrix.size() - row) + 1;
                row = matrix.size() - 1; 
            }
            else 
            {
                row = row + col;
                col = 0;
            }
            while(row >= 0 && col < matrix[0].size())
            {
                result.push_back(matrix[row][col]);
                row--;
                col++;
            }
        }
    }
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if(matrix.size() == 0)
            return result;
        bool reverse = true;
        for(int i = 0;i < matrix[0].size();i++)
        {
            GenerateSequence(matrix, 0, i, reverse, result);
            reverse = !reverse;
        }
        for(int i = 1;i < matrix.size();i++)
        {
            GenerateSequence(matrix, i, matrix[0].size() - 1, reverse, result);
            reverse = !reverse;
        }
        return result;
        
    }
};