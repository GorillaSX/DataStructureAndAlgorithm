/*
562. Longest Line of Consecutive One in Matrix
DescriptionHintsSubmissionsDiscussSolution
Given a 01 matrix M, find the longest line of consecutive one in the matrix. The line could be horizontal, vertical, diagonal or anti-diagonal.
Example:
Input:
[[0,1,1,0],
 [0,1,1,0],
 [0,0,0,1]]
Output: 3
*/
class Solution {
public:
    int longestLine(vector<vector<int>>& M) {
        int m = M.size();
        int n = m ? M[0].size() : 0;
        vector<vector<vector<int>>> counts(m, vector<vector<int>>(n, vector<int>(4, 0)));
        int longest = 0;
        for(int i = 0;i < m;i++)
        {
            for(int j = 0;j < n;j++)
            {
                if(M[i][j] == 1)
                {
                    counts[i][j][0] = 1;
                    counts[i][j][1] = 1;
                    counts[i][j][2] = 1;
                    counts[i][j][3] = 1;
                    if(j > 0)
                        counts[i][j][0] = max(1, 1 + counts[i][j-1][0]);
                    if(i > 0)
                        counts[i][j][1] = max(1, 1 + counts[i-1][j][1]);
                    if(i > 0 && j > 0)
                        counts[i][j][2] = max(1, 1 + counts[i-1][j-1][2]);
                    if(i> 0 && j < n-1)
                        counts[i][j][3] = max(1, 1 + counts[i-1][j+1][3]);
                    longest = max(longest, max(counts[i][j][0], max(counts[i][j][1], max(counts[i][j][2], counts[i][j][3]))));
                }
                
            }
        }
        return longest;
    }
};