/*
Given two words (beginWord and endWord), and a dictionary's word list, find all shortest transformation sequence(s) from beginWord to endWord, such that:

Only one letter can be changed at a time
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
For example,

Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log","cog"]
Return
  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]
Note:
Return an empty list if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.
*/
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<string> > findLadders(string beginWord, string endWord, vector<string>& wordList) {
            unordered_set<string> dict(wordList.begin(), wordList.end());
            bool find = false;
            queue<string> q;
            vector<vector<string> > results;
            if(dict.find(endWord) == dict.end())
                return results;
            q.push(beginWord);
            unordered_set<string> visit;
            visit.insert(beginWord);
            unordered_map<string,vector<pair<string,int> > > parents;
            int count = 1;
            while(!q.empty() && !find)
            {
                int size = q.size();
                for(int i = 0;i < size;i++)
                {
                    string tmp = q.front();
                    q.pop();
                    for(int m = 0;m < tmp.size();m++)
                    {
                        string cur = tmp;
                        for(int n = 0;n < 26;n++)
                        {
                            char c = 'a' + n;
                            cur[m] = c;
                            if(dict.find(cur) != dict.end())
                            {
                                if(cur == endWord)
                                    find = true;
                                if(visit.find(cur) == visit.end())
                                {
                                    q.push(cur);
                                    visit.insert(cur); 
                                }
                                if(tmp != cur)
                                    parents[cur].push_back(make_pair(tmp, count));
                            }
                        }
                    }
                }
                count++;
            }
            if(!find)
                return results;
            vector<string> tmp;
            parents[beginWord].clear();
            backtracking(parents, endWord, beginWord, tmp, results,  count);
            return results;

    }
    void backtracking(unordered_map<string, vector<pair<string,int> > >& parents, string cur, string end, vector<string>&tmp, vector<vector<string> >& results,int level)
    {
        if(cur == end)
        {
            tmp.push_back(cur);
            results.push_back(vector<string>(tmp.rbegin(), tmp.rend()));
            tmp.pop_back();
        }
        else 
        {
            tmp.push_back(cur);
            for(auto p : parents[cur])
            {
                if(p.second == level - 1)
                    backtracking(parents, p.first, end, tmp, results, level - 1);
            }
            tmp.pop_back();
        }        
    }
};

int main(void)
{
    string begin = "hit";
    string end = "cog";
    vector<string> list = {"hot", "dot", "dog", "lot", "log", "cog"};
    Solution s;
    vector<vector<string>> res = s.findLadders(begin, end, list);
    for(auto vec : res)
    {
        for(auto w: vec)
        {
            cout << w << " " ;
        }
        cout << endl;
    }
}