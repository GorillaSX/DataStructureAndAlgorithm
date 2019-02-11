/*
378. Kth Smallest Element in a Sorted Matrix
DescriptionHintsSubmissionsDiscussSolution
Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

Example:

matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,

return 13.
Note: 
You may assume k is always valid, 1 ≤ k ≤ n2.
*/
class comp 
{
public:
    bool operator()(const pair<int, pair<int,int>>& lhs, pair<int, pair<int,int>>& rhs) const
    {
        return lhs.first > rhs.first;
    }
};
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        typedef priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, comp> valuepq;
        valuepq minHeap;
        int m = matrix.size();
        int n = m ? matrix[0].size() : 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        visited[0][0] = true;
        minHeap.push(make_pair(matrix[0][0], make_pair(0,0)));
        while(k > 0)
        {
            auto topE = minHeap.top();
            minHeap.pop();
            if(--k == 0)
                return topE.first;
            int r = topE.second.first;
            int c = topE.second.second;
            if(r + 1 < m && visited[r+1][c] == false)
            {
                visited[r+1][c] = true;
                minHeap.push(make_pair(matrix[r+1][c], make_pair(r + 1, c)));
            }
            if(c + 1 < n && visited[r][c+1] == false)
            {
                visited[r][c+1] = true;
                minHeap.push(make_pair(matrix[r][c+1], make_pair(r, c+1)));
            }
        }
    }
};