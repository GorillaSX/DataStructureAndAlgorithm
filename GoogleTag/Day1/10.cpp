/*
Given a sorted array of integers nums and integer values a, b and c. Apply a quadratic function of the form f(x) = ax2 + bx + c to each element x in the array.

The returned array must be in sorted order.

Expected time complexity: O(n)

Example:
nums = [-4, -2, 2, 4], a = 1, b = 3, c = 5,

Result: [3, 9, 15, 33]

nums = [-4, -2, 2, 4], a = -1, b = 3, c = 5

Result: [-23, -5, 1, 7]
*/
class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        int l = 0, r = nums.size()- 1;
        vector<int> result;
        while(l <= r)
        {
            int left = a * nums[l] * nums[l] + b * nums[l] + c;
            int right = a * nums[r] * nums[r] + b * nums[r] + c;
            if((a > 0 && left >= right) or (a < 0 && left <= right) or ( a == 0 && b >= 0))
            {
                result.push_back(left);
                l++;
            }
            else 
            {
                result.push_back(right);
                r--;
            }
        }  
        if(a > 0)
            reverse(result.begin(), result.end());
        return result;
    }
};