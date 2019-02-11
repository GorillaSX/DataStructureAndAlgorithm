/*
200. Number of Islands
DescriptionHintsSubmissionsDiscussSolution
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input:
11110
11010
11000
00000

Output: 1
Example 2:

Input:
11000
11000
00100
00011

Output: 3
*/

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = m ? grid[0].size() : 0;
        vector<int> parent(m*n, 0);
        for(int i = 0;i < m * n;i++)
            parent[i] = i;
        int islands = m * n;
        for(int i = 0;i < m;i++)
        {
            for(int j = 0;j < n;j++)
            {
                if(grid[i][j] == 1)
                {
                    if(j < n -1 && grid[i][j+1] == 1)
                    {
                        int left = i * n + j;
                        int right = i * n + j + 1;
                        connect(parent, islans, left, right);
                    }
                    if(i < m -1 && grid[i+1][j] == 1)
                    {
                        int left = i * n + j;
                        int right = (i+1) * n + j;
                        connect(parent, islands, left, right);

                    }
                }
                else 
                {
                    islands--;
                }
            }
        }
        return islands;
    }
    void connect(vector<int>& parent, int& islands, int left, int right)
    {
        while(parent[left] != left)
            left = parent[left];
        while(parent[right] != right)
            right = parent[right];
        if(left != right)
        {
            parent[left] = right;
            islands--;
        }
    }
};