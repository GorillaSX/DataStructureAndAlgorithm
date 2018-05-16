/*Given a picture consisting of black and white pixels, find the number of black lonely pixels.

The picture is represented by a 2D char array consisting of 'B' and 'W', which means black and white pixels respectively.

A black lonely pixel is character 'B' that located at a specific position where the same row and same column don't have any other black pixels.

Example:
Input: 
[['W', 'W', 'B'],
 ['W', 'B', 'W'],
 ['B', 'W', 'W']]

Output: 3
Explanation: All the three 'B's are black lonely pixels.
Note:
The range of width and height of the input 2D array is [1,500].*/
class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        unordered_map<int, int> rowmaps;
        unordered_map<int, int> colmaps;
        vector<pair<int,int>> blackPos;
        int m = picture.size();
        int n = m  != 0 ? picture[0].size() : 0;
        for(int i = 0;i < m;i++)
        {
            for(int j = 0;j < n;j++)
            {
                if(picture[i][j] == 'B')
                {
                    rowmaps[i]++;
                    colmaps[j]++;
                    blackPos.push_back(make_pair(i,j));
                }
            }
        }
        int count = 0;
        for(auto black : blackPos)
        {
            if(rowmaps[black.first] != 1)
                continue;
            if(colmaps[black.second] != 1)
                continue;
            count++;
        }
        return count;
    }
};