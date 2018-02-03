/*
There is a new alien language which uses the latin alphabet. However, the order among letters are unknown to you. You receive a list of non-empty words from the dictionary, where words are sorted lexicographically by the rules of this new language. Derive the order of letters in this language.

Example 1:
Given the following words in dictionary,

[
  "wrt",
  "wrf",
  "er",
  "ett",
  "rftt"
]
The correct order is: "wertf".

Example 2:
Given the following words in dictionary,

[
  "z",
  "x"
]
The correct order is: "zx".

Example 3:
Given the following words in dictionary,

[
  "z",
  "x",
  "z"
]
The order is invalid, so return ""
*/

class Solution
{
    public:
    string alienOrder(vector<string>& words)
    {
        unordered_map<char, pair<int, vector<char>>> adj;
        for(int i = 0;i < words.size();i++)
        {
            for(int j = 0;j < words[i].size();j++)
                adj[words[i][j]].first = 0;            
        }

        for(int i = 0;i < words.size() - 1;i++)
        {
            char in = ' ';
            char out = ' ';
            if(words[i][0] != words[i+1][0])
            {
                in = words[i][0];
                out = words[i+1][0];
                adj[in].second.push_back(out);
                adj[out].first++;
            }
            else
            {
                int size = words[i].size() < words[i+1].size() ? words[i].size() : words[i+1].size();
                for(int index = 0;index < size; index++)
                {
                    if(words[i][index] != words[i+1][index])
                    {
                        in = words[i][index];
                        out = words[i+1][index];
                        adj[in].second.push_back(out);
                        adj[out].first++;
                    }
                }
            }
        }
        string res = "";
        queue<char> start;
        for(auto& ele : adj)
        {
            if(ele.second.first == 0)
                start.push(ele.first);
        }
        while(start.size() != 0)
        {
            char in = start.front();
            start.pop();
            res.push_back(in);
            for(auto out : adj[in].second)
            {
                adj[out].first--;
                if(adj[out].first == 0)
                    start.push(out);
            }
            adj.erase(in);
        }
        if(adj.size() != 0)
            return "";
        else
            return res;
    }
};