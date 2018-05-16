/*
Given a binary array, find the maximum number of consecutive 1s in this array if you can flip at most one 0.

Example 1:
Input: [1,0,1,1,0]
Output: 4
Explanation: Flip the first zero will get the the maximum number of consecutive 1s.
    After flipping, the maximum number of consecutive 1s is 4.
Note:

The input array will only contain 0 and 1.
The length of input array is a positive integer and will not exceed 10,000
Follow up:
What if the input numbers come in one by one as an infinite stream? In other words, you can't store all numbers coming from the stream as it's too large to hold in memory. Could you solve it efficiently?
*/
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int left = 0;
        int contiguous = 0;
        int res = 0;
        bool space = false;
        for(int i = 0;i < nums.size();i++)
        {
            if(nums[i] == 1)
                contiguous++;
             else if(nums[i] == 0 and (i + 1 < nums.size() and nums[i+1] == 0))
             {
                 res = max(res, left + contiguous + 1);
                 left = 0, contiguous = 0;
                 space = true;
             }
             else if(nums[i] == 0)
             {
                 if(left != 0)
                    res = max(res, left + contiguous + 1);
                 else
                     res = max(res, contiguous + 1);
                 left = contiguous;
                 contiguous = 0;
                 space = true;
             }
        }
        if(left != 0)
            res = max(res, left + contiguous + 1);
        else
            res = max(res, contiguous + (space ? 1 : 0));
        return res; 
    }
};
//the solution below could solve  follow up question. 
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int left = 0, right = 0, prev = 0, ans = 0;
        bool space = false;
        for(auto n : nums)
        {
            if(n == 1)
            {
                if(prev == 1)
                    right++;
                else if(prev == 0)
                    right = 1;
                prev = 1;
            }
            else 
            {
                if(prev == 1)
                {
                    ans = max(ans, left + right + 1);
                    left = right;
                    right = 0;
                }
                else
                {
                    left = 0;
                    right = 0;
                }
                prev = 0;
                space = true;
            }
        }
        ans = max(ans, left + right + (space ? 1 : 0));
        return ans;
    }
};