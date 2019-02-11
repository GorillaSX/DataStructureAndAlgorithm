/*
286. Walls and Gates
DescriptionHintsSubmissionsDiscussSolution
You are given a m x n 2D grid initialized with these three possible values.

-1 - A wall or an obstacle.
0 - A gate.
INF - Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.
Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.

Example: 

Given the 2D grid:

INF  -1  0  INF
INF INF INF  -1
INF  -1 INF  -1
  0  -1 INF INF
After running your function, the 2D grid should be:

  3  -1   0   1
  2   2   1  -1
  1  -1   2  -1
  0  -1   3   4
  */
class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int m = rooms.size();
        int n = m ? rooms[0].size() : 0;
        for(int i = 0;i < m;i++)
        {
            for(int j = 0;j < n;j++)
            {
                if(rooms[i][j] == 0)
                {
                    updateDistance(rooms, i, j, m, n,0);
                }
            }
        }          
    }
    void updateDistance(vector<vector<int>>& rooms, int r, int c, int m ,int n, int dis)
    {
        int delta[5] = {0, 1, 0, -1, 0};
        for(int i = 0;i < 4;i++)
        {
            int row = r + delta[i];
            int col = c + delta[i + 1];
            if(row >= 0 && row < m && col >= 0 && col < n && rooms[row][col] != -1 && rooms[row][col] > 1 + dis)
            {
                rooms[row][col] = 1 + dis;
                updateDistance(rooms, row, col, m, n, 1 + dis);
            }
        }
    }
};