/*
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:

Input:
s = "catsanddog"
wordDict = ["cat", "cats", "and", "sand", "dog"]
Output:
[
  "cats and dog",
  "cat sand dog"
]
Example 2:

Input:
s = "pineapplepenapple"
wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
Output:
[
  "pine apple pen apple",
  "pineapple pen apple",
  "pine applepen apple"
]
Explanation: Note that you are allowed to reuse a dictionary word.
Example 3:

Input:
s = "catsandog"
wordDict = ["cats", "dog", "sand", "and", "cat"]
Output:
[]
*/
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<char, vector<string>> StartWith;
        for(auto word : wordDict)
            StartWith[word[0]].push_back(word);       
        for(auto ele : StartWith)
            sort(ele.second.begin(), ele.second.end(), [&](const string& a, const string & b){return a.size() > b.size();});
        vector<string> result;        
        unordered_map<string, bool> memory;
        backtracking(s,  StartWith,  result, "", memory);
        return result;
    }
    bool backtracking(string s, unordered_map<char, vector<string>>& StartWith, vector<string>& result, string cur, unordered_map<string, bool>& memory)
    {
        if(s == "")
        {
            result.push_back(cur.substr(0, cur.size() - 1));
            return true;
        }

        bool res = false;
        for(auto word : StartWith[s[0]])
        {
            string tmp = s.substr(0, word.size());
            if(tmp == word)
            {
                string next = cur + tmp + " ";
                string test = s.substr(tmp.size());
                if(memory.count(test) == 0 || memory[test] == true)
                {
                    if(backtracking(s.substr(tmp.size()), StartWith, result, next, memory))
                        res = true;
                }
            }
        }
        memory[s] = res;
        return res;
    }
};