/*
Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.

Example: 

Input: s = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: the subarray [4,3] has the minimal length under the problem constraint.
Follow up:
If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n). 
*/
//SOlution :O(n)
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
           vector<int> prefixSum(nums.size() + 1, 0);
            for(int i = 1;i < prefixSum.size();i++)
                prefixSum[i] = prefixSum[i-1] + nums[i-1];
           int start = 0, end = 1;
           int miniSize = INT_MAX; 
           while(end < prefixSum.size())
           {
               while(prefixSum[end] - prefixSum[start] >= s)
               {
                   miniSize = min(miniSize, end - start);
                   start++;
               }
               end++;
           }  
           return miniSize == INT_MAX ? 0 : miniSize;
           
    }
};

//O(nlogn) Solution 
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
           int minSize = INT_MAX;
           vector<int> prefix(nums.size() + 1, 0);
           for(int i = 1;i < prefix.size();i++)
               prefix[i] = prefix[i-1] + nums[i-1]; 
           for(int i = 0;i < prefix.size();i++)
           {
               if(prefix[i] >= s)
               {
                   int target = prefix[i] - s;
                   auto it = upper_bound(prefix.begin(), prefix.begin()+i, target);
                   minSize = min(minSize, int(prefix.begin() + i - it + 1)); 
               }
           }
        return minSize == INT_MAX ? 0 : minSize;
            
    }
};