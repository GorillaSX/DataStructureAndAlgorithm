/*
Given string S and a dictionary of words words, find the number of words[i] that is a subsequence of S.

Example :
Input: 
S = "abcde"
words = ["a", "bb", "acd", "ace"]
Output: 3
Explanation: There are three words in words that are a subsequence of S: "a", "acd", "ace".
Note:

All words in words and S will only consists of lowercase letters.
The length of S will be in the range of [1, 50000].
The length of words will be in the range of [1, 5000].
The length of words[i] will be in the range of [1, 50].
*/
class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        vector<vector<int>> index(26, vector<int>(0,0));
        for(int i = 0;i < S.size();i++)
        {
            index[S[i] - 'a'].push_back(i);
        }
        int count = 0;
        for(auto word : words)
        {
            if(index[word[0]-'a'].size() == 0)
                break;
            int prev = 0;
            int find = true;
            for(auto c : word)
            {
                
                auto it = lower_bound(index[c-'a'].begin(), index[c-'a'].end(), prev);
                if(it == index[c-'a'].end())
                {
                    find = false;
                    break;
                }
                else 
                    prev = *it + 1;
            }
            if(find == true)
                count++;
            
        }
        return count;
    }
};

