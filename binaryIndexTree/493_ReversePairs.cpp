/*
Given an array nums, we call (i, j) an important reverse pair if i < j and nums[i] > 2*nums[j].

You need to return the number of important reverse pairs in the given array.

Example1:

Input: [1,3,2,3,1]
Output: 2
Example2:

Input: [2,4,3,5,1]
Output: 3
Note:
The length of the given array will not exceed 50,000.
All the numbers in the input array are in the range of 32-bit integer
*/

class Solution {
public:
    void update(vector<int>& sums, int i, int val)
    {
        while(i < sums.size())
        {
            sums[i] += val;
            i += (i & - i);
        }
    }
    int sum(vector<int>& sums, int i)
    {
        int sum = 0;
        while(i > 0)
        {
            sum += sums[i];
            i -= (i & -i);
        }
        return sum;
    }
    int reversePairs(vector<int>& nums) {
       vector<int> tmp = nums;
       sort(tmp.begin(), tmp.end());
       unordered_map<int,int> hash;
       for(int i = 0;i < tmp.size();i++)
       {
           hash[tmp[i]] = i + 1;
       }
       vector<int> sums = vector<int>(nums.size() + 1, 0);
       int total = 0;
       for(int i = nums.size() - 1;i >= 0;i--)
       {
           int target = nums[i] > 0 ? nums[i] % 2 == 0 ? (nums[i] / 2) - 1 : nums[i] / 2 : (nums[i] / 2) - 1;
           auto it = upper_bound(tmp.begin(), tmp.end(), target);
           int index = it - tmp.begin();
           total += sum(sums, index);
           update(sums, hash[nums[i]], 1);
       }
       return total;
    }
};