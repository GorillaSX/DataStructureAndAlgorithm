/*
Given an encoded string, return it's decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].

Examples:

s = "3[a]2[bc]", return "aaabcbc".
s = "3[a2[c]]", return "accaccacc".
s = "2[abc]3[cd]ef", return "abcabccdcdcdef".

*/
class Solution {
public:
    string decodeString(string s) {
        stack<pair<string, int>> mystack;
        string cur  = "";
        int times = 0;
        for(auto c : s)
        {
            if(isalpha(c))
                cur += c;
            else if(isdigit(c))
                times = times * 10 + (c - '0');
            else if(c == '[')
            {
                mystack.push(make_pair(cur, times));
                cur = "";
                times = 0;
            }
            else if(c == ']')
            {
                auto p = mystack.top();
                mystack.pop();
                string tmp = "";
                for(int i = 0;i < p.second;i++)
                    tmp += cur;
                cur = p.first + tmp;
                times = 0;
            }
        }
        return cur; 
    }
};