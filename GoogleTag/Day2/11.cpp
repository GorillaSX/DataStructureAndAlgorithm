/*
361. Bomb Enemy
DescriptionHintsSubmissionsDiscussSolution
Given a 2D grid, each cell is either a wall 'W', an enemy 'E' or empty '0' (the number zero), return the maximum enemies you can kill using one bomb.
The bomb kills all the enemies in the same row and column from the planted point until it hits the wall since the wall is too strong to be destroyed.
Note that you can only put the bomb at an empty cell.

Example:
For the given grid

0 E 0 0
E 0 W E
0 E 0 0

return 3. (Placing a bomb at (1,1) kills 3 enemies)
Credits:
Special thanks to @memoryless for adding this problem and creating all test cases.

*/
class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = m ? grid[0].size() : 0;
        vector<int> colEnemy(n, 0);
        int result = 0;
        for(int i = 0;i < m;i++)
        {
            int rowCount = 0;
            for(int j = 0;j < n;j++)
            {
               if(j == 0 || grid[i][j - 1] == 'W')
               {
                    rowCount = 0;
                    int tmp = j;
                    while(tmp < n && grid[i][tmp] != 'W')
                    {
                        if(grid[i][tmp] == 'E')
                            rowCount++;
                        tmp++;
                    }
               } 
               if(i == 0 || grid[i-1][j] == 'W')
               {
                   colEnemy[j] = 0;
                    int tmp = i;
                    while(tmp < m && grid[tmp][j] != 'W')
                    {
                        if(grid[tmp][j] == 'E')
                            colEnemy[j]++;
                        tmp++;
                    }
               }
               if(grid[i][j] == '0')
               {
                   result = max(result, rowCount + colEnemy[j]);
               }
            }
        }
        return result;
    }
};