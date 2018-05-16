/*
Given a string, we can "shift" each of its letter to its successive letter, for example: "abc" -> "bcd". We can keep "shifting" which forms the sequence:

"abc" -> "bcd" -> ... -> "xyz"
Given a list of strings which contains only lowercase alphabets, group all strings that belong to the same shifting sequence.

For example, given: ["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"], 
A solution is:

[
  ["abc","bcd","xyz"],
  ["az","ba"],
  ["acef"],
  ["a","z"]
]
*/
class Solution {
public:
    string generateStartString(string word)
    {
        if(word.size() == 0)
            return word;
        int step = word[0] - 'a';
        for(int i = 0;i < word.size();i++)
        {
            if(word[i] - 'a' - step >= 0)
            {
                word[i] = char(word[i] - step);
            }
            else
            {
                word[i] = char('z' + (word[i] - 'a' - step + 1));
            }
        }
        return word;
    }
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> groups;
        for(auto word : strings)
             groups[generateStartString(word)].push_back(word);
        
        for(auto ele : groups)
            result.push_back(ele.second);
        return result;
    }
};