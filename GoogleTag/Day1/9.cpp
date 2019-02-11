/*
249. Group Shifted Strings
DescriptionHintsSubmissionsDiscussSolution
Given a string, we can "shift" each of its letter to its successive letter, for example: "abc" -> "bcd". We can keep "shifting" which forms the sequence:

"abc" -> "bcd" -> ... -> "xyz"
Given a list of strings which contains only lowercase alphabets, group all strings that belong to the same shifting sequence.

Example:

Input: ["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"],
Output: 
[
  ["abc","bcd","xyz"],
  ["az","ba"],
  ["acef"],
  ["a","z"]
]
*/
class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> maps;
        for(auto str : strings)
        {
            if(str != "")
            {
                int offset = str[0] - 'a';
                string tmp = str;
                for(int i = 0;i < str.size();i++)
                {
                    if(tmp[i] - 'a' >= offset)
                        tmp[i] = tmp[i] - offset;
                    else 
                        tmp[i] = 26 + tmp[i] - offset;
                }
                maps[tmp].push_back(str);
            }
        }
        vector<vector<string>> results;
        for(auto& ele : maps)
        {
            results.push_back(ele.second);
        }
        return results;
    }
};