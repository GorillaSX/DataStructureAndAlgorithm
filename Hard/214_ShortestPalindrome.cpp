/*
Given a string s, you are allowed to convert it to a palindrome by adding characters in front of it. Find and return the shortest palindrome you can find by performing this transformation.

Example 1:

Input: "aacecaaa"
Output: "aaacecaaa"
Example 2:

Input: "abcd"
Output: "dcbabcd"
*/
class Solution {
public:
    string shortestPalindrome(string s) {
        string rev(s);
        reverse(rev.begin(), rev.end());
        for(int i = 0;i < s.size();i++)
        {
            if(s.substr(0, s.size() - i) == rev.substr(i))
                return rev.substr(0, i) + s;
        }
        return "";
        
    }
};