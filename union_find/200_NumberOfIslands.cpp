/*
 * Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
 *
 * Example 1:
 * 11110
 * 11010
 * 11000
 * 00000
 *
 * Answer: 1
 */

//Union find solution

class UnionFind
{
     public:
        UnionFind(vector<vector<char>>& grid)
        {
           int rn = grid.size();
           int cn = rn != 0 ? grid[0].size() : 0;
           for(int i = 0;i < rn; i++)
           {
               for(int j = 0;j < cn;j++)
               {
                  if(grid[i][j] == '1')
                  {
                      arry.push_back(count);
                      index[i * cn + j] = count;
                      count++;
                  }
               }
           }
        }
        int find(int n)
        {
           while(arry[n] != n)
           {
              n = arry[n];
           }
           return n;
        }

        void unifon(int left, int right)
        {
            int l = index[left];
            int r = index[right];
            int lr = find(l);
            int rr = find(r);
            if(lr != rr)
            {
               arry[lr] = rr;
               count--;
            }
        }


        int getCount(void)
        {
            return count;
        }

    
     private:
        unordered_map<int,int> index;
        vector<int> arry;
        int count = 0;
};


class Solution {
        public:
        int numIslands(vector<vector<char>>& grid) 
        {
            UnionFind uf(grid);
            int rn = grid.size();
            int cn = rn != 0 ? grid[0].size() : 0;
            for(int i = 0;i < rn; i++)
            {
                for(int j = 0;j < cn; j++)
                {
                    if(grid[i][j] == '1')
                    {
                        if(j + 1 < cn && grid[i][j+1] == '1')
                              uf.unifon(i*cn + j , i * cn + j + 1);
                        if(i + 1 < rn && grid[i+1][j] == '1')
                              uf.unifon(i*cn + j, (i + 1) * cn + j;
                    }
                }
            }
            return uf.getCount();
        }
};
