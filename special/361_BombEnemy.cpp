/*
Given a 2D grid, each cell is either a wall 'W', an enemy 'E' or empty '0' (the number zero), return the maximum enemies you can kill using one bomb.
The bomb kills all the enemies in the same row and column from the planted point until it hits the wall since the wall is too strong to be destroyed.
Note that you can only put the bomb at an empty cell.

Example:
For the given grid

0 E 0 0
E 0 W E
0 E 0 0

return 3. (Placing a bomb at (1,1) kills 3 enemies)
*/
// time O(mn) space O(mn)
class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = m ? grid[0].size() : 0;
        vector<vector<int>> count(m, vector<int>(n, 0));
        int result = 0;
        for(int i = 0;i < m;i++)
        {
            int tmpcountleft = 0, tmpcountright = 0, rightindex = n-1;
            for(int j = 0;j < n;j++, rightindex--)
            {
                if(grid[i][j] == 'W')
                    tmpcountleft = 0;
                else if(grid[i][j] == 'E')
                    tmpcountleft++;
                else if(grid[i][j] == '0')
                    count[i][j] += tmpcountleft;
                
                if(grid[i][rightindex] == 'W')
                    tmpcountright = 0;
                else if(grid[i][rightindex] == 'E')
                    tmpcountright++;
                else if(grid[i][rightindex] == '0')
                    count[i][rightindex] += tmpcountright;
            }
        }
        
        for(int i = 0;i < n;i++)
        {
            int topcount = 0, botcount = 0, botindex = m - 1;
            for(int j = 0;j < m;j++, botindex--)
            {
                if(grid[j][i] == 'W')
                    topcount = 0;
                else if(grid[j][i] == 'E')
                    topcount++;
                else if(grid[j][i] == '0')
                    count[j][i] += topcount;
                
                if(grid[botindex][i] == 'W')
                    botcount = 0;
                else if(grid[botindex][i] == 'E')
                    botcount++;
                else if(grid[botindex][i] == '0')
                    count[botindex][i] += botcount;
            }
        }
        
        for(int i = 0;i < m;i++)
        {
            for(int j = 0;j < n;j++)
            {
                result = max(result, count[i][j]);
            }
        }
        return result; 
    }
};

// time O(mn) time O(n)
class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = m ? grid[0].size() : 0;
        int result = 0;
        vector<int> colcount(n, 0);
        for(int i = 0;i < m;i++)
        {
            int rowcount = 0;
            for(int j = 0;j < n;j++)
            {
                if(!j || grid[i][j-1] == 'W')
                {
                    int tmpj = j;
                    rowcount = 0;
                    while(tmpj < n and grid[i][tmpj] != 'W')
                    {
                        if(grid[i][tmpj] == 'E')
                            rowcount++;
                        tmpj++;
                    }
                }
                if(!i || grid[i-1][j] == 'W')
                {
                    int tmpi = i;
                    int colc = 0;
                    while(tmpi < m and grid[tmpi][j] != 'W')
                    {
                        if(grid[tmpi][j] == 'E')
                            colc++;
                        tmpi++;
                    }
                    colcount[j] = colc;
                }
                if(grid[i][j] == '0')
                    result = max(result, rowcount + colcount[j]);
            }
            
        }
        return result;
    }
};