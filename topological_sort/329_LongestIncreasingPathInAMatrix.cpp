/*
Given an integer matrix, find the length of the longest increasing path.

From each cell, you can either move to four directions: left, right, up or down. You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).

Example 1:

nums = [
  [9,9,4],
  [6,6,8],
  [2,1,1]
]
Return 4
The longest increasing path is [1, 2, 6, 9].

Example 2:

nums = [
  [3,4,5],
  [3,2,6],
  [2,2,1]
]
Return 4
The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
*/

class Solution 
{
    public:
    int longestIncreasingPath(vector<vector<int>>& matrix)
    {
        unordered_map<int, pair<int, vector<int>>> adj;
        int rn =  matrix.size();
        int cn = rn != 0 ? matrix[0].size() : 0;
        int in, out = 0;
        if(rn == 1 && cn == 1)
            return 1;

        for(int i = 0;i < rn;i++)
        {
            for(int j = 0;j < cn; j ++)
            {
                if(j != cn - 1)
                {
                    if(matrix[i][j] != matrix[i][j+1])
                    {
                        in = matrix[i][j] < matrix[i][j+1] ? i * cn + j : i * cn + j + 1;
                        out = matrix[i][j] < matrix[i][j+1] ? i * cn + j + 1 : i * cn + j;
                        if(adj.count(in) == 0)
                            adj[in].first = 0;
                        adj[in].second.push_back(out);
                        if(adj.count(out) == 0)
                            adj[out].first = 0;
                        adj[out].first++;
                    }
                    else
                    {
                        if(adj.count(i * cn + j) == 0)
                            adj[i*cn + j].first = 0;
                    }
                }
                if(i != rn - 1)
                {
                    if(matrix[i][j] != matrix[i+1][j])
                    {
                        in = matrix[i][j] < matrix[i+1][j] ? i * cn + j : (i + 1) * cn + j;
                        out = matrix[i][j] < matrix[i+1][j] ? (i + 1) * cn + j : i * cn + j;
                        if(adj.count(in) == 0)
                            adj[in].first = 0;
                        adj[in].second.push_back(out);
                        if(adj.count(out) == 0)
                            adj[out].first = 0;
                        adj[out].first++;
                    }
                    else
                    {
                        if(adj.count(i * cn + j) == 0)
                            adj[i*cn + j].first = 0;
                    }
                }
            }
        }
        queue<int> start;
        for(auto& ele : adj)
        {
            if(ele.second.first == 0)
                start.push(ele.first);
        }
        int count = 0;
        while(start.size() != 0)
        {
            count++;
            int s = start.size();
            for(int i = 0;i < s;i++)
            {
                int in = start.front();
                start.pop();
                for(auto& out : adj[in].second)
                {
                    adj[out].first--;
                    if(adj[out].first == 0)
                        start.push(out);
                }
            }
        }
        return count;
    }
};