/*
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

class Solution{
    public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> chart;
         int maxL = 0;
         int start = 0;
         for(int i = 0;i < s.length();i++)
         {
            chart[s[i]]++;
            if(chart[s[i]] == 1)
                maxL = max(maxL, i - start + 1);
            else
            {
                while(chart[s[i]] >1)
                {
                    chart[s[start++]]--;
                }
            }
         }
         return maxL;
    }
};