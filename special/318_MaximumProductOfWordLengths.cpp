/*
Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. You may assume that each word will contain only lower case letters. If no such two words exist, return 0.

Example 1:
Given ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
Return 16
The two words can be "abcw", "xtfn".

Example 2:
Given ["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
Return 4
The two words can be "ab", "cd".

Example 3:
Given ["a", "aa", "aaa", "aaaa"]
Return 0
No such pair of words.

Credits:
Special thanks to @dietpepsi for adding this problem and creating all test cases.
*/
class Solution {
public:
    
    int maxProduct(vector<string>& words) {
        unordered_map<int, int> maxlen;
        for(auto word : words)
        {
            int code = 0;
            for(auto c : word)
            {
                code |= (1 << (c - 'a'));
            }
            maxlen[code] = max(maxlen[code], int(word.size()));
        }
        int ans = 0;
        for(auto a : maxlen)
        {
            for(auto b : maxlen)
            {
                if((a.first & b.first) == 0)
                {
                    ans = max(ans, a.second * b.second);
                }
            }
        }
        return ans;
    }
};