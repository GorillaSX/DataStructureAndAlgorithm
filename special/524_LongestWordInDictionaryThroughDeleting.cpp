/*
Given a string and a string dictionary, find the longest string in the dictionary that can be formed by deleting some characters of the given string. If there are more than one possible results, return the longest word with the smallest lexicographical order. If there is no possible result, return the empty string.

Example 1:
Input:
s = "abpcplea", d = ["ale","apple","monkey","plea"]

Output: 
"apple"
Example 2:
Input:
s = "abpcplea", d = ["a","b","c"]

Output: 
"a"
Note:
All the strings in the input will only contain lower-case letters.
The size of the dictionary won't exceed 1,000.
The length of all the strings in the input won't exceed 1,000.
*/
class Solution {
public:
    bool checkSubstring(string a, string b)
    {
        int i = 0, j = 0;
        for(i = 0, j = 0;i < a.size() and j < b.size();i++)
        {
            if(a[i] == b[j])
            {
                j++;
            }
        }
        return j == b.size();
        
    }
    string findLongestWord(string s, vector<string>& d) {
        string result = "";
        for(auto b : d)
        {
            if(checkSubstring(s, b))
            {
                if(b.size() > result.size())
                    result = b;
                else if(b.size() == result.size())
                    result = min(result, b);
            }
        }
        return result;
    }
};