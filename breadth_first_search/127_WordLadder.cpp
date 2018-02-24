/*
Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time.
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
For example,

Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log","cog"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.
UPDATE (2017/1/20):
The wordList parameter had been changed to a list of strings (instead of a set of strings). Please reload the code definition to get the latest changes.
*/

class Solution 
{
    public:
        int ladderLength(string beginWord, string endWord, vector<string>& wordList)
        {
            unordered_set<string> dict(wordList.begin(), wordList.end());
            if(dict.find(endWord) == dict.end())
                return 0;
            queue<string> trans;
            int count = 1;
            trans.push(beginWord);
            while(!trans.empty())
            {
                int size = trans.size();
                for(int i = 0;i < size;i++)
                {
                    string tmp = trans.front();
                    for(int index = 0; index < tmp.size(); index++)
                    {
                        string cur = tmp;
                        for(int j = 0;j < 26;j++)
                        {
                            char c = 'a' + j;
                            cur[index] = c;
                            if(cur == endWord)
                                return count + 1;
                            else if(dict.find(cur) != dict.end())
                            {
                                trans.push(cur);
                                dict.erase(cur);
                            }
                        }
                    }
                    trans.pop();
                }
                count++;
            }
            return 0;
        }
};