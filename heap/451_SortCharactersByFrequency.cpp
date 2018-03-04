/*
Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:

Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input:
"cccaaa"

Output:
"cccaaa"

Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input:
"Aabb"

Output:
"bbAa"

Explanation:
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
*/

//Solution one using priority_queue
class comp
{
    public:
    bool operator()(const pair<char, int>& lhs, pair<char,int>& rhs)
    {
        return lhs.second < rhs.second;
    }
};
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for(auto c : s)
            mp[c]++;
        typedef priority_queue<pair<char, int>, vector<pair<char,int>>, comp> pq;
        pq mpq;
        for(auto e : mp)
        {
            mpq.push(make_pair(e.first, e.second));
        }
        string res = "";
        while(!mpq.empty())
        {
            pair<char, int> tmp = mpq.top();
            mpq.pop();
            res.append(tmp.second, tmp.first);
        }
        return res;
    }
};

//Solution two, using bucket sort

class Solution 
{
    public:
    string frequencySort(string s)
    {
        unordered_map<char, int> mp;
        for(char e : s)
            mp[e]++;
        vector<string> freq(s.size()+1, "");
        for(auto ele : mp)
        {
            freq[ele.second].append(ele.second, ele.first);
        }
        string res = "";
        for(auto i = freq.size() - 1;i > 0;i--)
        {
            if(freq[i] != "")
            {
                res.append(freq[i]);
            }
        }
        return res;
    }
};