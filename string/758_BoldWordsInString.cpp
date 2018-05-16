/*
Given a set of keywords words and a string S, make all appearances of all keywords in S bold. Any letters between <b> and </b> tags become bold.

The returned string should use the least number of tags possible, and of course the tags should form a valid combination.

For example, given that words = ["ab", "bc"] and S = "aabcd", we should return "a<b>abc</b>d". Note that returning "a<b>a<b>b</b>c</b>d" would use more tags, so it is incorrect.

Note:

words has length in range [0, 50].
words[i] has length in range [1, 10].
S has length in range [0, 500].
All characters in words[i] and S are lowercase letters.
*/
class Solution {
public:
    string boldWords(vector<string>& words, string S) {
        if(S.size() == 0)
            return S;
        unordered_map<char, unordered_set<string>> wordsmap;
        for(auto  w : words)
        {
            wordsmap[w[0]].insert(w);
        }
        vector<bool> mask(S.size(), false);
        for(int i = 0;i < S.size();i++)
        {
            for(auto w : wordsmap[S[i]])
            {
                string tmp = S.substr(i, w.size());
                if(tmp == w)
                {
                    for(int j = 0;j < w.size();j++)
                        mask[i+j] = true;
                }
                    
            }
        }
        string result = "";
        for(int i = 0;i < mask.size();i++)
        {  
            if(mask[i] == true)
            {
                if(i == 0 or mask[i-1] == false)
                    result += "<b>";
            }
            result += S[i];
            if(mask[i] == true)
            {
                if(i == mask.size() - 1 or mask[i+1] == false)
                    result += "</b>";
            }
        }
        return result;
        
    }
};