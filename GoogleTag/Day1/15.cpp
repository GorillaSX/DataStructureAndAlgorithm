/*
487. Max Consecutive Ones II
DescriptionHintsSubmissionsDiscussSolution
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
        int left = 0, right = 0, zeros = 0;
        bool prezero = false;
        int result = 0;
        for(int i = 0;i < nums.size();i++)
        {
            if(nums[i] == 0)
            {
                result = max(result, 1 + left + right);
                ++zeros;
                if(zeros == 2)
                {
                    left = 0;
                    right = 0;
                }
                else if (zeros == 1)
                {
                    left = right;
                    right = 0;
                }
                prezero = true;
            }
            else 
            {
                right++;
                zeros = 0;
            }
        }
        result = max(result, right + (prezero ? 1 + left : 0));
        return result;
    }
};