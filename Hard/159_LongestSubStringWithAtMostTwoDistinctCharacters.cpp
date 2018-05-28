/*
Given a string s , find the length of the longest substring t  that contains at most 2 distinct characters.

Example 1:

Input: "eceba"
Output: 3
Explanation: t is "ece" which its length is 3.
Example 2:

Input: "ccaabbb"
Output: 5
Explanation: t is "aabbb" which its length is 5.
*/
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        if(s.size() == 0)
            return 0;
        unordered_map<char, int> charcount;
        int res = 0, start = 0, end = 0;
        for(end = 0; end < s.size(); end++ )   
        {
            if(charcount.count(s[end]) != 0)
                charcount[s[end]]++;
            else 
            {
                if(charcount.size() < 2)
                    charcount[s[end]] = 1;
                else 
                {
                    res = max(res, end - start);
                    while(charcount.size() >= 2)
                    {
                        charcount[s[start]]--;
                        if(charcount[s[start]] == 0)
                            charcount.erase(s[start]);
                        start++;
                    }
                    charcount[s[end]] = 1;
                }
            }
        }
        res = max(res, end - start );
        return res; 
    }
};