/*
Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple copies of the substring together. You may assume the given string consists of lowercase English letters only and its length will not exceed 10000.
Example 1:
Input: "abab"

Output: True

Explanation: It's the substring "ab" twice.
Example 2:
Input: "aba"

Output: False
Example 3:
Input: "abcabcabcabc"

Output: True

Explanation: It's the substring "abc" four times. (And the substring "abcabc" twice.)
*/
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int len = s.size() / 2;
        for(int l = 1; l <= len;l++)
        {
            if(s.size() % l == 0)
            {
                string target = s.substr(0, l);
                int i = 0;
                for(i = l; i < s.size(); i+= l)
                {
                    if(s.substr(i, l) != target)
                        break;
                }
                if( i == s.size())
                    return true;
                }
        }
        return false;
    }
};
//
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        for(int l = 1; l <= s.size() / 2;l++)
        {
            if(s.size() % l == 0 and s.substr(0, s.size() - l) == s.substr(l)) return true;
        }
        return false;
    }
};