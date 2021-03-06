/*

Sometimes people repeat letters to represent extra feeling, such as "hello" -> "heeellooo", "hi" -> "hiiii".  Here, we have groups, of adjacent letters that are all the same character, and adjacent characters to the group are different.  A group is extended if that group is length 3 or more, so "e" and "o" would be extended in the first example, and "i" would be extended in the second example.  As another example, the groups of "abbcccaaaa" would be "a", "bb", "ccc", and "aaaa"; and "ccc" and "aaaa" are the extended groups of that string.

For some given string S, a query word is stretchy if it can be made to be equal to S by extending some groups.  Formally, we are allowed to repeatedly choose a group (as defined above) of characters c, and add some number of the same character c to it so that the length of the group is 3 or more.  Note that we cannot extend a group of size one like "h" to a group of size two like "hh" - all extensions must leave the group extended - ie., at least 3 characters long.

Given a list of query words, return the number of words that are stretchy. 

Example:
Input: 
S = "heeellooo"
words = ["hello", "hi", "helo"]
Output: 1
Explanation: 
We can extend "e" and "o" in the word "hello" to get "heeellooo".
We can't extend "helo" to get "heeellooo" because the group "ll" is not extended.
Notes:

0 <= len(S) <= 100.
0 <= len(words) <= 100.
0 <= len(words[i]) <= 100.
S and all words in words consist only of lowercase letters
*/
class Solution {
public:
    pair<string, vector<int>> compress(string word)
    {
        pair<string, vector<int>> result;
        int start = 0;
        vector<int> counts;
        string rep = "";
        for(int i = 0;i < word.size();i++)
        {
            if(word[i] != word[start])
            {
                rep += word[start];
                counts.push_back(i - start);
                start = i;
            }
        }
        rep += word[start];
        counts.push_back(word.size() - start);
        return make_pair(rep, counts);
    }
    int expressiveWords(string S, vector<string>& words) {
        pair<string, vector<int>> reps = compress(S);
        int count = 0;
        for(auto word : words)
        {
            pair<string, vector<int>> curs = compress(word);
            if(curs.first == reps.first)
            {
                int find = true;
                for(int i = 0;i < curs.second.size();i++)
                {
                    if((reps.second[i] < 3 and reps.second[i] != curs.second[i]) or (reps.second[i] >= 3 and curs.second[i] > reps.second[i]))
                    {
                        find = false;
                        break;
                    }
                }
                if(find)
                    count++;
                
            }
        }
        return count;
    }
};

class Solution {
public:
    vector<pair<char, int>> compress(string word)
    {
        vector<pair<char, int>> result;
        int start = 0;
        for(int i = 0;i < word.size();i++)
        {
            if(word[i] != word[start])
            {
                result.push_back(make_pair(word[start], i - start));
                start = i;
            }
        }
        result.push_back(make_pair(word[start], word.size() - start));
        return result;
    }
    int expressiveWords(string S, vector<string>& words) {
        vector<pair<char,int>> reps = compress(S);
        int count = 0;
        for(auto word : words)
        {
            vector<pair<char, int>> curs = compress(word);
            if(curs.size() == reps.size())
            {
                int find = true;
                for(int i = 0;i < curs.size();i++)
                {
                    if(reps[i].first != curs[i].first or (reps[i].second < 3 and reps[i].second != curs[i].second) or (reps[i].second >= 3 and curs[i].second > reps[i].second))
                    {
                        find = false;
                        break;
                    }
                }
                if(find)
                    count++;
                
            }
        }
        return count;
    }
};