/*
Given a sorted integer array without duplicates, return the summary of its ranges.

Example 1:

Input:  [0,1,2,4,5,7]
Output: ["0->2","4->5","7"]
Explanation: 0,1,2 form a continuous range; 4,5 form a continuous range.
Example 2:

Input:  [0,2,3,4,6,8,9]
Output: ["0","2->4","6","8->9"]
Explanation: 2,3,4 form a continuous range; 8,9 form a continuous range.
*/
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        if(nums.size() == 0)
            return result;
        string start = ""; 
        for(int i = 0; i < nums.size();i++)
        {
           if(i == nums.size() - 1)
           {
               start = start + to_string(nums[i]);
               result.push_back(start);
               return result;
           }
           else if(nums[i+1] - nums[i] == 1 and start == "")
           {
               start = to_string(nums[i]) + "->";
           }
           else if(nums[i+1] - nums[i] != 1)
           {
               start = start + to_string(nums[i]);
               result.push_back(start);
               start = "";
           }
        }
        
    }
};