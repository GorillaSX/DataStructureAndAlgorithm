/*
Given an array of n distinct non-empty strings, you need to generate minimal possible abbreviations for every word following rules below.

Begin with the first character and then the number of characters abbreviated, which followed by the last character.
If there are any conflict, that is more than one words share the same abbreviation, a longer prefix is used instead of only the first character until making the map from word to abbreviation become unique. In other words, a final abbreviation cannot map to more than one original words.
If the abbreviation doesn't make the word shorter, then keep it as original.
Example:
Input: ["like", "god", "internal", "me", "internet", "interval", "intension", "face", "intrusion"]
Output: ["l2e","god","internal","me","i6t","interval","inte4n","f2e","intr4n"]
Note:
Both n and the length of each word will not exceed 400.
The length of each word is greater than 1.
The words consist of lowercase English letters only.
The return answers should be in the same order as the original array.
*/
class Trie 
{
    public:
    Trie(){}
    void insert(string& word)
    {
        Trie* node = this;
        for(int i = 0;i < word.size();i++)
        {
           if(node->child[word[i] - 'a'] == NULL)
                node->child[word[i] - 'a'] = new Trie();
           node = node->child[word[i] - 'a'];
           (node->count)++;
        }
    }
    
    string FindAbbr(string& word)
    {
        Trie* node = this;
        for(int i = 0;i < word.size();i++)
        {
            node = node->child[word[i] - 'a'];
            if(node->count == 1)
            {
                if(i == word.size() - 1)
                    return word;
                string abb = word.substr(0, i + 1) + to_string(word.size() - i - 2) + word.back();
                return (abb.size() >= word.size() ? word : abb);
            }
        }
        
    }
    Trie* child[26] = {NULL};
    int count = 0;
    ~Trie()
    {
        for(int i = 0;i < 26;i++)
        {
            if(child[i] != NULL)
                delete child[i];
        }
    }
};
class Solution {
public:
    vector<string> wordsAbbreviation(vector<string>& dict) {
        unordered_map<string,vector<int>> groups;
        for(int i = 0;i < dict.size();i++)
        {
            string word = dict[i];
            string key = word.front() + to_string(word.size() - 2) + word.back();
            groups[key].push_back(i);
        }        
        vector<string> res(dict.size(), "");
        for(auto group : groups)
        {
            GenerateAbbr(group.first, group.second, dict, res);
        }
        return res;
    }
    void GenerateAbbr(string abbr, vector<int>& words, vector<string>& dict, vector<string>& res)
    {
        if(words.size() == 1)
        {
            res[words[0]] = (abbr.size() >= dict[words[0]].size() ? dict[words[0]] : abbr);
            return ;
        }
        Trie* root = new Trie();
        for(auto word : words)
        {
            root->insert(dict[word]);
        }
        for(auto word : words)
        {
            res[word] = root->FindAbbr(dict[word]);
        }
        delete root;
    }
};
