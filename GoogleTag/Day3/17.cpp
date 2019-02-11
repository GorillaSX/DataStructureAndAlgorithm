/*
809. Expressive Words
DescriptionHintsSubmissionsDiscussSolution
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
    int expressiveWords(string S, vector<string>& words) {
        vector<pair<char,int>>&& rep = compress(S);
        int count = 0;
        for(auto word : words)
        {
            vector<pair<char,int>>&& repw = compress(word);
            if(repw.size() == rep.size())
            {
                int i = 0; 
                for(i = 0;i < rep.size();i++)
                {
                    if(rep[i].first == repw[i].first)
                    {
                        if((rep[i].second <= 2 && rep[i].second == repw[i].second) or (rep[i].second >= 3 && repw[i].second <= rep[i].second))
                            continue;
                        break;
                    }
                    break;
                }
                if(i == rep.size())
                    count++;
            }
        }
        return count;
        
    }
    vector<pair<char,int>> compress(string s)
    {
        vector<pair<char,int>> result;
        int i = 0;
        while(i < s.size())
        {
            char c = s[i];
            int count = 0;
            while(i < s.size() && s[i] == c)
            {
                count++;
                i++;
            }
            result.push_back(make_pair(c, count));
        }
        return result;
    }
};