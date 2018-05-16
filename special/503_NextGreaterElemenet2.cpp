/*
Given a circular array (the next element of the last element is the first element of the array), print the Next Greater Number for every element. The Next Greater Number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, output -1 for this number.

Example 1:
Input: [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2; 
The number 2 can't find next greater number; 
The second 1's next greater number needs to search circularly, which is also 2.
Note: The length of given array won't exceed 10000.*/
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> result(nums.size(), -1);
        vector<int> tmp(nums.begin(), nums.end());
        tmp.insert(tmp.end(), nums.begin(), nums.end());
        stack<pair<int,int>> largeNums;
        for(int i = 0;i < tmp.size();i++)
        {
            while(largeNums.empty() == false and largeNums.top().first < tmp[i])
            {
                result[largeNums.top().second] = tmp[i];
                largeNums.pop();
            }
            if(i < nums.size())
                largeNums.push(make_pair(tmp[i], i));
        }
        return result;
        
    }
};