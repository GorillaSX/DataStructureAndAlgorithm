/*
A 2d grid map of m rows and n columns is initially filled with water. We may perform an addLand operation which turns the water at position (row, col) into a land. Given a list of positions to operate, count the number of islands after each addLand operation. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example:

Given m = 3, n = 3, positions = [[0,0], [0,1], [1,2], [2,1]].
Initially, the 2d grid grid is filled with water. (Assume 0 represents water and 1 represents land).

0 0 0
0 0 0
0 0 0
Operation #1: addLand(0, 0) turns the water at grid[0][0] into a land.

1 0 0
0 0 0   Number of islands = 1
0 0 0
Operation #2: addLand(0, 1) turns the water at grid[0][1] into a land.

1 1 0
0 0 0   Number of islands = 1
0 0 0
Operation #3: addLand(1, 2) turns the water at grid[1][2] into a land.

1 1 0
0 0 1   Number of islands = 2
0 0 0
Operation #4: addLand(2, 1) turns the water at grid[2][1] into a land.

1 1 0
0 0 1   Number of islands = 3
0 1 0
We return the result as an array: [1, 1, 2, 3]
*/

class Solution
{
    public: 
    vector<int> numIslands2(int m, int n , vector<pair<int,int>>& positions)
    {
        vector<int> array;
        vector<int> results;
        for(int i = 0;i < m * n; i++)
        {
            array.push_back(i);
        }
        int curN = 0;
        int delta[5] = {0 , 1, 0, -1, 0};
        unordered_set<int> islandSet;
        for(auto& p : positions)
        {
            curN++;
            islandSet.insert(p.first * n + p.second);
            for(int i = 0;i < 4;i++)
            {
                int r = p.first + delta[i];
                int c = p.second + delta[i+1];
                if(r >= 0 && r < m && c >=0 && c < n && islandSet.count(r *n + c) == 1)
                {
                    int left = p.first * n + p.second;
                    int right = r * n + c;
                    while(array[left] != left)
                        left = array[left];
                    while(array[right] != right)
                        right =array[right];
                    if(left != right)
                    {
                        array[left] = right;
                        curN--;
                    }
                }
            }
            results.push_back(curN);
        }
        return results;
    }
};