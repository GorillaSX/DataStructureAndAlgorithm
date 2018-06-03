/*
Given two arrays of length m and n with digits 0-9 representing two numbers. Create the maximum number of length k <= m + n from digits of the two. The relative order of the digits from the same array must be preserved. Return an array of the k digits.

Note: You should try to optimize your time and space complexity.

Example 1:

Input:
nums1 = [3, 4, 6, 5]
nums2 = [9, 1, 2, 5, 8, 3]
k = 5
Output:
[9, 8, 6, 5, 3]
Example 2:

Input:
nums1 = [6, 7]
nums2 = [6, 0, 4]
k = 5
Output:
[6, 7, 6, 0, 4]
Example 3:

Input:
nums1 = [3, 9]
nums2 = [8, 9]
k = 3
Output:
[9, 8, 9]
*/
class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = 0, n2 = 0;
        int num1size = nums1.size(), num2size = nums2.size();
        vector<int> result;
        while(k != 0)
        {
            if(nums1size - n1 + nums2size - n2 <= k)
            {
                if(n1 < num1size && nums1[n1] > nums[n2])
                {
                    result.push_back(nums1[n1++]);
                }
                else 
                    result.push_back(nums2[n2++]);

            }
            else 
            {
                int tmp1 = n1, tmp2 = n2, oneIndex = -1, twoIndex = -1, m = -1;
                while(tmp1 <= min((num1size - (k - (nums2size - n2))), num1size -1))
                {
                    if(nums1[tmp1] > m)
                    {
                        m = nums1[tmp1];
                        oneIndex = tmp1;
                    }
                }
                while(tmp2 <= min((nums2size - (k - (nums1size - n1))), num2size - 1))
                {
                    if(nums2[tmp2] > m)
                    {
                        m = nums2[tmp2];
                        twoIndex = tmp2;
                    }
                }
                if(twoIndex != -1)
                {
                    result.push_back(nums2[twoIndex]);
                    n2 = twoIndex++;
                }
                else 
                {
                    result.push_back(nums1[oneIndex]);
                    n1 = oneIndex++;
                }
            }
            k--;
        }       
        return results;
    }
};