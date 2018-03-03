/*
Given a non-empty 2D matrix matrix and an integer k, find the max sum of a rectangle in the matrix such that its sum is no larger than k.

Example:
Given matrix = [
  [1,  0, 1],
  [0, -2, 3]
]
k = 2
The answer is 2. Because the sum of rectangle [[0, 1], [-2, 3]] is 2 and 2 is the max number no larger than k (k = 2).

Note:
The rectangle inside the matrix must have an area > 0.
What if the number of rows is much larger than the number of columns?

*/

class Solution  
{
    public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k)
    {
        if(matrix.empty())
            return 0;
        int m = matrix.size();
        int n = m != 0 ? matrix[0].size() : 0;
        int res = INT_MIN;
        for(int i = 0;i < n;i++)
        {
            vector<int> rsum(m, 0);
            for(int j = i;j < n;j++)
            {
                for(int index = 0;index < m;index++)
                {
                    rsum[index] += matrix[index][j];
                }
                set<int> sums;
                int sum = 0;
                for(auto s : rsum)
                {
                    sum += s;
                    if(sum <= k)
                        res = max(res, sum);
                    auto it = sums.lower_bound(sum - k);
                    if(it != sums.end())
                        res = max(res, sum - *it);
                    sums.insert(sum);
                }
            }
        }
        return res;
    }
};