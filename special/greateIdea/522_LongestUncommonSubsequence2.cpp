/*
Given a list of strings, you need to find the longest uncommon subsequence among them. The longest uncommon subsequence is defined as the longest subsequence of one of these strings and this subsequence should not be any subsequence of the other strings.

A subsequence is a sequence that can be derived from one sequence by deleting some characters without changing the order of the remaining elements. Trivially, any string is a subsequence of itself and an empty string is a subsequence of any string.

The input will be a list of strings, and the output needs to be the length of the longest uncommon subsequence. If the longest uncommon subsequence doesn't exist, return -1.

Example 1:
Input: "aba", "cdc", "eae"
Output: 3
Note:

All the given strings' lengths will not exceed 10.
The length of the given list will be in the range of [2, 50].
*/
class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        unordered_map<string,  int> maps;
        for(auto word : strs)
        {
            maps[word]++;
        }
        int longest = -1;
        for(auto ele : maps)
        {
            if(ele.second == 1)
            {
                if(NotOtherSubsequence(ele.first, strs))
                    longest = max(longest, int(ele.first.size()));
            }
        }
        return longest;
    }
    bool NotOtherSubsequence(string word, vector<string>& strs)
    {
        for(auto str : strs)
        {
            if(str != word)
                 if(isSubsequence(word, str))
                    return false;
        }
        return true;
    }
    bool isSubsequence(string word, string str)
    {
        if(str.size() < word.size())
            return false;
        int j = 0;
        for(int i = 0;i < str.size();i++)
        {
            if(str[i] == word[j])
                j++;
        }
        return j == word.size();
    }
};