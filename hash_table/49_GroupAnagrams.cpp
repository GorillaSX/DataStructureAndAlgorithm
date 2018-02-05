/*
Given an array of strings, group anagrams together.

For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
Return:

[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]
*/

class Solution
{
    public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        unordered_map<string, vector<string>> group;
        for(auto& str : strs)
        {
            string tmp = string(26, '0');
            for(auto& c : str)
            {
                tmp[c - 'a'] = tmp[c - 'a'] + 1;
            }
            group[tmp].push_back(str);
        }
        vector<vector<string>> res;
        for(auto& ele : group)
            res.push_back(ele.second);
        return res;
    }
};