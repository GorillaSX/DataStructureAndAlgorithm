/*
An image is represented by a binary matrix with 0 as a white pixel and 1 as a black pixel. The black pixels are connected, i.e., there is only one black region. Pixels are connected horizontally and vertically. Given the location (x, y) of one of the black pixels, return the area of the smallest (axis-aligned) rectangle that encloses all black pixels.

Example:

Input:
[
  "0010",
  "0110",
  "0100"
]
and x = 0, y = 2

Output: 6
*/

class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
       int m = image.size();
       int n  = m ? image[0].size() : 0;
       vector<vector<bool>> visited(m, vector<bool>(n, false));
       visited[x][y] = true;
       queue<pair<int,int>> myq;
        
       myq.push(make_pair(x, y));
       int left = n - 1, right = 0, top = m - 1, bot = 0;
       int delta[5] = {0, 1, 0, -1, 0}; 
       while(!myq.empty())
       {
          pair<int,int> pos = myq.front();
          myq.pop();
          left = min(left,  pos.second);
          right = max(right, pos.second);
          top = min(top, pos.first);
          bot = max(bot, pos.first); 
          for(int i = 0;i < 4;i++)
          {
              int r = pos.first + delta[i];
              int c = pos.second + delta[i+1];
              if(r >= 0 and r < m and c >= 0 and c < n && image[r][c] == '1' && visited[r][c] == false)
              {
                 visited[r][c] = true;
                 myq.push(make_pair(r, c)); 
              }
          }  
       }   
       return (right - left + 1) * (bot - top + 1); 
    }
};