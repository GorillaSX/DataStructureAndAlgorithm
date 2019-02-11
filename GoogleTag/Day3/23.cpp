/*
417. Pacific Atlantic Water Flow
DescriptionHintsSubmissionsDiscussSolution
Given an m x n matrix of non-negative integers representing the height of each unit cell in a continent, the "Pacific ocean" touches the left and top edges of the matrix and the "Atlantic ocean" touches the right and bottom edges.

Water can only flow in four directions (up, down, left, or right) from a cell to another one with height equal or lower.

Find the list of grid coordinates where water can flow to both the Pacific and Atlantic ocean.

Note:
The order of returned grid coordinates does not matter.
Both m and n are less than 150.
Example:

Given the following 5x5 matrix:

  Pacific ~   ~   ~   ~   ~ 
       ~  1   2   2   3  (5) *
       ~  3   2   3  (4) (4) *
       ~  2   4  (5)  3   1  *
       ~ (6) (7)  1   4   5  *
       ~ (5)  1   1   2   4  *
          *   *   *   *   * Atlantic

Return:

[[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (positions with parentheses in above matrix)
*/
class Solution 
{
public:
    vector<pair<int,int>> pacificAtlantic(vector<vector<int>>& matrix)
    {
        int m = matrix.size();
        int n = m ? matrix[0].size() : 0;
        vector<pair<int,int>> results;
        if(m == 0)
            return results;
        vector<vector<int>> reach(m, vector<int>(n,0));
        bfs(reach, matrix, make_pair(0,0), 0,0,m,n);
        bfs(reach, matrix, make_pair(m-1, n-1), m-1, n-1, m, n);
        for(int i = 0;i < m;i++)
        {
            for(int j = 0;j < n;j++)
            {
                if(reach[i][j] == 2)
                    results.push_back(make_pair(i,j));
            }
        }
        return results;
    }
    void bfs(vector<vector<int>>& reach, vector<vector<int>>& matrix, pair<int,int> start, int sideone, int sidetwo, int m, int n)
    {
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        visited[start.first][start.second] = true;
        queue<pair<int,int>> PacStart;
        PacStart.push(start);
        int delta[5] = {0, 1, 0, -1, 0};
        while(!PacStart.empty())
        {
            auto front = PacStart.front();
            PacStart.pop();
            reach[front.first][front.second]++;
            for(int i = 0;i < 4;i++)
            {
                int row = front.first + delta[i];
                int col = front.second + delta[i+1];
                if(row >= 0 && row < m && col >= 0 && col < n && visited[row][col] == false)
                {
                    if(matrix[row][col] >= matrix[front.first][front.second] or (row == sideone or col == sidetwo))
                    {
                        visited[row][col] = true;
                        PacStart.push(make_pair(row, col));
                    }
                }
            }
        }
    }
};