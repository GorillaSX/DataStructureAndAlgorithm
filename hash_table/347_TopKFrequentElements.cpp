/*
Given a non-empty array of integers, return the k most frequent elements.

For example,
Given [1,1,1,2,2,3] and k = 2, return [1,2].

Note: 
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> count;
        int maxN = 0;
        for(auto n : nums)
        {
            if(count.count(n) == 0)
                count[n] = 0;
            count[n]++;
            maxN = max(maxN, count[n]);
        }
        vector<vector<int>> bowl = vector<vector<int>>(maxN, vector<int>());
        vector<int> res;
        for(auto & ele : count)
        {
            bowl[ele.second - 1].push_back(ele.first);
        }
        for(int i = bowl.size()- 1;i >= 0;i--)
        {
            for(auto& n : bowl[i])
            {
                if(k <= 0)
                    break;
                res.push_back(n);
                k--;
            }
        }
        return res;
    }
};