/*
Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order, too.

You need to find the shortest such subarray and output its length.

Example 1:
Input: [2, 6, 4, 8, 10, 9, 15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
Note:
Then length of the input array is in range [1, 10,000].
The input array may contain duplicates, so ascending order here means <=.
*/
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
       if(nums.size() == 1)
           return 0;
        int left = 0;
        while(left < nums.size() - 1 &&nums[left] <= nums[left+1])
            left++;
        if(left == nums.size() - 1)
            return 0;
        int right = nums.size() - 1;
        while(right >= 0 && nums[right] >= nums[right-1])
            right--;
        int minimum = INT_MAX, maximum = INT_MIN;
        for(int i = left;i <= right;i++)
        {
            minimum = min(minimum, nums[i]);
            maximum = max(maximum, nums[i]);
        }
        for(int i = 0;i < left;i++)
        {
            if(minimum < nums[i])
            {
                left = i;
                break;
            }
        }
        for(int i = nums.size() - 1;i > right;i--)
        {
            if(maximum > nums[i])
            {
                right = i;
                break;
            }
        }
        return right - left + 1;
        
    }
};