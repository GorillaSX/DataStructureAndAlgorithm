/*
229. Majority Element II
DescriptionHintsSubmissionsDiscussSolution
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

Note: The algorithm should run in linear time and in O(1) space.

Example 1:

Input: [3,2,3]
Output: [3]
Example 2:

Input: [1,1,1,3,3,2,2,2]
Output: [1,2]
*/
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> result;
        int count1 = 0, candi1 = 0;
        int count2 = 0, candi2 = 0;
        for(auto n : nums) 
        {
            if(n == candi1)
                count1++;
            else if(n == candi2)
                count2++;
            else if(count1 == 0)
            {
                candi1 = n;
                count1 = 1;
            }    
            else if(count2 == 0)
            {
                candi2 = n;
                count2 = 1;
            }
            else 
            {
                count1--;
                count2--;
            }
        }
        count1 = 0, count2 = 0;
        for(auto n : nums)
        {
            if(n == candi1)
                count1++;
            else if(n == candi2)
                count2++;
        }
        if(count1 > nums.size() / 3)    result.push_back(candi1);
        if(count2 > nums.size() / 3) result.push_back(candi2);
        return result;
    }
};