/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

The array may contain duplicates.
*/
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        return find(nums, left, right); 
    }
    int find(vector<int>& nums, int left, int right)
    {
        while(right - left > 1)
        {
            int mid = (left + right) / 2;
            if(nums[mid] < nums[left])
                right = mid;
            else
            {
               if(nums[mid] > nums[right])
                    return  find(nums, mid + 1, right);
               else if(nums[mid] < nums[right])  
                   return find(nums, left, mid - 1);
               else 
               {
                   int l = find(nums, left, mid - 1);
                   int r = find(nums, mid + 1, right);
                    return l < r ? l : r; 
               } 
            }
            
                
        }
        return nums[left] < nums[right] ? nums[left] : nums[right];
    }
};