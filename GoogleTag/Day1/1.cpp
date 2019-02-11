/*
524. Longest Word in Dictionary through Deleting
DescriptionHintsSubmissionsDiscussSolution
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
*/
class Solution 
{
    public:
    bool checkSubString(string a, string b)
    {
        int i = 0, j = 0;
        while(i < a.size() && j < b.size())
        {
            if(a[i] == b[j])
            {
                j++;
            }
            i++;
        }
        return j == b.size();
    }
    string findLongestWord(string s, vector<string>& d)
    {
        string result = "";
        for(auto b : d)
        {
            if(checkSubString(s, b))
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