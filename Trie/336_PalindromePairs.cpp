/*

Given a list of unique words, find all pairs of distinct indices (i, j) in the given list, so that the concatenation of the two words, i.e. words[i] + words[j] is a palindrome.

Example 1:
Given words = ["bat", "tab", "cat"]
Return [[0, 1], [1, 0]]
The palindromes are ["battab", "tabbat"]
Example 2:
Given words = ["abcd", "dcba", "lls", "s", "sssll"]
Return [[0, 1], [1, 0], [3, 2], [2, 4]]
The palindromes are ["dcbaabcd", "abcddcba", "slls", "llssssll"]
Credits:
Special thanks to @dietpepsi for adding this problem and creating all test cases.
*/

bool checkPalindrome(string word)
{
    int l = 0, r = word.size() - 1;
    while(l < r)
    {
        if(word[l] == word[r])
        {
            l++;
            r--;
        }
        else
        {
            return false;
        }
    }
    return true;
}
class Trie 
{
public:
    Trie* child[26] = {NULL};
    bool isWord = false;
    int depth = 0;
    vector<int> NotEndIndices;
    vector<int> endIndices;
    Trie(int d):depth(d){}
    void insert(string word, int index)
    {
        Trie*node = this;
        for(int i = 0;i < word.size();i++)
        {
            node->NotEndIndices.push_back(index);
            if(node->child[word[i] - 'a'] == NULL)
                node->child[word[i]- 'a'] = new Trie(i+1);
            node = node->child[word[i] - 'a'];
        }
        node->isWord = true;
        node->endIndices.push_back(index);
    }
    unordered_set<int> query(string word, vector<string>& words)
    {
        unordered_set<int> result;
        Trie* node = this;
        if(checkPalindrome(word))
            result.insert(node->endIndices.begin(), node->endIndices.end());
        for(int i = 0;i < word.size();i++)
        {
            if(node->child[word[i] - 'a'] == NULL)
            {
                if(checkPalindrome(word.substr(i)))
                    result.insert(node->endIndices.begin(), node->endIndices.end());
                return result;
            }
            if(checkPalindrome(word.substr(i)))
                  result.insert(node->endIndices.begin(), node->endIndices.end());
            node = node->child[word[i] - 'a'];
        }
        result.insert(node->endIndices.begin(), node->endIndices.end());
        for(auto index : node->NotEndIndices)
        {
            if(checkPalindrome(words[index].substr(0, words[index].size() - node->depth)))
                result.insert(index);
        }
        return result;
        
    }
};

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
         Trie root(0);
         for(int i = 0;i < words.size();i++)
         { 
             string tmp(words[i].rbegin(), words[i].rend());
             root.insert(tmp, i);
         }
         vector<vector<int>> results;
         for(int i = 0;i < words.size();i++)
         {
             unordered_set<int> r = root.query(words[i], words);
             if(r.size() != 0)
             {
                 for(auto& index : r)
                 {
                    if(index != i)
                        results.push_back(vector<int>{i, index});
                 }
             }
         }
         return results;
    }
};