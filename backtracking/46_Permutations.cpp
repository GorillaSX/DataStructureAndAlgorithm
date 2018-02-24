/*
Given a collection of distinct numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
       vector<vector<int>> results;
       helper(results, vector<int>(), nums);
       return results; 
    }

    void helper(vector<vector<int>>& results, vector<int> cur, vector<int> nums)
    {
      if(nums.size() == 0)
      {
        results.push_back(cur);
      }
      else 
      {
        for(int i = 0;i < nums.size();i++)
        {
            cur.push_back(nums[i]);
            vector<int> next = nums;
            next.erase(next.begin() + i);
            helper(results, cur, next);
            cur.pop_back();
        }
      }
    }
};