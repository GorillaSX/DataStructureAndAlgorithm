/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while(right - left > 1)
        {
            int mid = (left + right) / 2;
            if(nums[mid] < nums[left])
                right = mid;
            else if(nums[mid] > nums[left] && nums[mid] < nums[right])
                right = mid - 1;
            else if(nums[mid] > nums[left] && nums[mid] > nums[right])
                left = mid + 1;
        }
        return nums[left] < nums[right] ? nums[left] : nums[right];
    }
};