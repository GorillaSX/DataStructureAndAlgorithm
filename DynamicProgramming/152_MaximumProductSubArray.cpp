/*

Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.

Example 1:

Input: [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
*/

class Solution
{
    public:
    int maxProduct(vector<int>& nums)
    {
        int cur = 1,pos = 1, neg = 1, maxN = INT_MIN;
        for(auto& n : nums)
        {
            maxN = max(maxN, n);
            if(n > 0)
            {
                pos = pos * n;
                cur = cur * n;
                maxN = max(maxN, cur);
            }
            else if(n == 0)
            {
                pos = 1;
                neg = 1;
                cur = 1;
            }
            else
            {
                if(neg > 0)
                {
                    neg = neg * pos * n;
                    cur = 1;
                }
                else
                {
                    int tmpneg = neg;
                    neg = cur * n;
                    cur = tmpneg * pos * n;
                    maxN = max(cur, maxN);
                }
                pos = 1;
            }
        }
        return maxN;
    }
};