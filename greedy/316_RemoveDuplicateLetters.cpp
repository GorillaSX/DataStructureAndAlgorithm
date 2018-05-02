/*
Given a string which contains only lowercase letters, remove duplicate letters so that every letter appear once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

Example:
Given "bcabc"
Return "abc"

Given "cbacdcbc"
Return "acdb"

Credits:
Special thanks to @dietpepsi for adding this problem and creating all test cases.
*/

class Solution {
public:
    string removeDuplicateLetters(string s) {
        int charcount[26] = {0};
        stack<char> chars;
        bool visited[26] = {false};
        for(auto c : s)
            charcount[c-'a']++;
        for(auto& c : s)
        {
            charcount[c-'a']--;
            if(visited[c-'a'] == true)
                continue;
            while(chars.size() != 0 and chars.top() > c and charcount[chars.top() - 'a'] > 0)
            {
                visited[chars.top() - 'a'] = false;
                chars.pop();
            }
            visited[c-'a'] = true;
            chars.push(c);
        }
        string res = "";
        while(chars.size() > 0)
        {
            res = chars.top() + res;
            chars.pop();
        }
        return res;
        
    }
};