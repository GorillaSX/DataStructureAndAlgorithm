/*
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
*/
class comp
{
    public:
    bool operator()(pair<pair<int,int>, int> const& lhs, pair<pair<int,int>, int> const& rhs) const
    {
        return lhs.second > rhs.second;
    }
};
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        typedef priority_queue<pair<pair<int,int>, int>, vector<pair<pair<int,int>, int>>, comp> pq;
        pq mypq;
        mypq.push(make_pair(make_pair(0,0), matrix[0][0]));
        if(k == 1)
            return matrix[0][0];
        int m =matrix.size();
        int n = m != 0? matrix[0].size() : 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        visited[0][0] = true;
        while(k > 1)
        {
            pair<pair<int,int>,int> tmp = mypq.top();
            mypq.pop();
            pair<int,int> pos = tmp.first;
            if(pos.second + 1 < n && visited[pos.first][pos.second + 1] == false)
            {
                mypq.push(make_pair(make_pair(pos.first, pos.second + 1), matrix[pos.first][pos.second+1]));
                visited[pos.first][pos.second + 1] = true;
            }
            if(pos.first + 1 < m && visited[pos.first + 1][pos.second] == false)
            {
                mypq.push(make_pair(make_pair(pos.first + 1, pos.second), matrix[pos.first + 1][pos.second]));
                visited[pos.first + 1][pos.second] = true;
            }
            k--;
        }
        return mypq.top().second;
    }
};