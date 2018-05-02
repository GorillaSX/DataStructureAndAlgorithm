/*
In a 2D grid of 0s and 1s, we change at most one 0 to a 1.

After, what is the size of the largest island? (An island is a 4-directionally connected group of 1s).

Example 1:

Input: [[1, 0], [0, 1]]
Output: 3
Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3.
Example 2:

Input: [[1, 1], [1, 0]]
Output: 4
Explanation: Change the 0 to 1 and make the island bigger, only one island with area = 1.
Example 3:

Input: [[1, 1], [1, 1]]
Output: 4
Explanation: Can't change any 0 to 1, only one island with area = 1.
 

Notes:

1 <= grid.length = grid[0].length <= 50.
0 <= grid[i][j] <= 1.
*/

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int largest = 0;
        int m = grid.size();
        if(m == 1)
            return 1;
        vector<int> islands(m *m, 0);
        vector<int> islandsize(m*m ,1);
        for(int i = 0;i < m*m; i++)
            islands[i] = i;
        int delta[8] = {0, 1, 1, 0, 0, -1, -1, 0}; 
        for(int i = 0;i < m;i++)
        {
            for(int j = 0;j < m;j++)
            {
                if(grid[i][j] == 1)
                {
                    for(int step = 0; step <= 2; step+= 2)
                    {
                        int row = i + delta[step];
                        int col = j + delta[step + 1];
                        if(row >= 0 and row < m and col >= 0 and col < m and grid[row][col] == 1)
                        {
                            int left = i * m + j;
                            while(islands[left] != left)
                                left = islands[left];
                            int right = row * m + col;
                            while(islands[right] != right)
                                right = islands[right];
                            if(left != right)
                            {
                                islands[left] = right;
                                islandsize[right] += islandsize[left];
                                largest = max(largest, islandsize[right]);
                            } 
                        }
                    }
                }
            }
        }
        for(int i = 0;i < m; i++)
        {
            for(int j = 0;j < m;j++)
            {
                if(grid[i][j] == 0)
                {
                    unordered_set<int> islandsgroup;
                    for(int step = 0; step <= 6;step+=2)
                    {
                        int row = i + delta[step];
                        int col = j + delta[step+1];
                        if(row >= 0 and row < m and col >= 0 and col < m and grid[row][col] == 1)
                        {
                            int right = row * m  + col;
                            while(islands[right] != right)
                                right = islands[right];
                            islandsgroup.insert(right);
                        }
                    }
                    int cur = 1;
                    for(auto& g : islandsgroup)
                        cur += islandsize[g];
                    largest = max(cur, largest);
                }
            }
        }
        for(auto& n : islandsize)
            cout << n << endl; 
        return largest;
    }
};