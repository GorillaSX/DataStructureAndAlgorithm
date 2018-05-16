/*Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:

Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
             Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false*/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<char, vector<string>> words;
        for(auto word : wordDict)
            words[word[0]].push_back(word);
        for(auto ele : words)
        {
            sort(ele.second.begin(), ele.second.end(), [&](const string& a, const string& b){ return a.size() > b.size();});
        }
        unordered_map<string, bool> memory;
        return dfscheck(s, words, memory);
    }
    
    bool dfscheck(string s, unordered_map<char, vector<string>>& words, unordered_map<string, bool>& memory)
    {
        
        if(s == "")
            return true;
        if(memory.count(s) != 0)
            return memory[s];
        
        if(words.count(s[0]) == 0)
        {
            memory[s] = false;
            return false;
        }
        for(auto word : words[s[0]])
        {
            if(s.substr(0, word.size()) == word)
            {
                if(dfscheck(s.substr(word.size()), words, memory))
                {
                    memory[s] = true;
                    return true;
                }
            }
        }
        memory[s] = false;
        return false;
    }
};