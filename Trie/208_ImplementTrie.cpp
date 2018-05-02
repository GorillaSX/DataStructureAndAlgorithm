/*
Implement a trie with insert, search, and startsWith methods.

Note:
You may assume that all inputs are consist of lowercase letters a-z.
*/
class Trie {
public:
    /** Initialize your data structure here. */
    Trie* child[26];
    bool end = false;
    Trie() {
        for(int i = 0;i < 26;i++)
            child[i] = NULL;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
       Trie* node = this;
       for(int i = 0;i < word.size();i++)
       {
           if(node->child[word[i] - 'a'] == NULL)
                node->child[word[i] - 'a'] = new Trie();
           node = node->child[word[i] - 'a'];
       } 
       node->end = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
       Trie* node = this;
       for(int i = 0;i < word.size(); i++)
       {
           if(node->child[word[i] - 'a'] == NULL)
                return false;
           else 
                node = node->child[word[i] - 'a'];
       }
       return node->end;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string word) {
        Trie* node = this;
        for(int i = 0;i < word.size();i++)
        {
            if(node->child[word[i] - 'a'] == NULL)
                return false;
            else 
                node = node->child[word[i] - 'a'];
        }    
        return true;
    }
};