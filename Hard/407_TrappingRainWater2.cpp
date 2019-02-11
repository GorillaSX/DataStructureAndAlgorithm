/*
407. Trapping Rain Water II
DescriptionHintsSubmissionsDiscussSolution
Given an m x n matrix of positive integers representing the height of each unit cell in a 2D elevation map, compute the volume of water it is able to trap after raining.

Note:
Both m and n are less than 110. The height of each unit cell is greater than 0 and is less than 20,000.
*/
class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        int n = m ? heightMap[0].size() : 0;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> bouder;
        vector<vector<bool>> visited(m, vector<bool>(n));
        for(int i = 0;i < n;i++)
        {
            visited[0][i] = true;
            visited[m-1][i] = true;
            bouder.emplace(vector<int>({heightMap[0][i], 0, i}));
            bouder.emplace(vector<int>({heightMap[m-1][i], m-1, i}));
        }
        for(int i = 0;i < m;i++)
        {
            visited[i][0] = true;
            visited[i][n-1] = true;
            bouder.emplace(vector<int>({heightMap[i][0], i, 0}));
            bouder.emplace(vector<int>({heightMap[i][n-1],i, n-1}));
        }
        int result = 0;
        int delta[5] = {0, 1, 0, -1, 0};
        while(!bouder.empty())
        {
            auto lowest = bouder.top();bouder.pop();
            for(int i = 0;i < 4;i++)
            {
                int r = lowest[1] + delta[i];
                int c = lowest[2] + delta[i+1];
                if(r >= 0 && r < m && c >= 0 && c < n && visited[r][c] == false)
                {
                    visited[r][c] = true;
                    if(heightMap[r][c] >= lowest[0])
                    {
                        bouder.emplace(vector<int>({heightMap[r][c], r, c}));
                    }
                    else 
                    {
                        result += (lowest[0] - heightMap[r][c]);
                        bouder.emplace(vector<int>({lowest[0], r, c}));
                    }
                }
            }
        }
        return result;
    }
};