/*In English, we have a concept called root, which can be followed by some other words to form another longer word - let's call this word successor. For example, the root an, followed by other, which can form another word another.

Now, given a dictionary consisting of many roots and a sentence. You need to replace all the successor in the sentence with the root forming it. If a successor has many roots can form it, replace it with the root with the shortest length.

You need to output the sentence after the replacement.

Example 1:
Input: dict = ["cat", "bat", "rat"]
sentence = "the cattle was rattled by the battery"
Output: "the cat was rat by the bat"
Note:
The input will only have lower-case letters.
1 <= dict words number <= 1000
1 <= sentence words number <= 1000
1 <= root length <= 100
1 <= sentence words length <= 1000
*/
class Trie 
{
    public:
    Trie(){}
    void insert(string word)
    {
        Trie* node = this;
        for(int i = 0;i < word.size();i++)
        {
            if(node->end == true)
                return;
            if(node->child[word[i] - 'a'] == NULL)
                node->child[word[i] - 'a'] = new Trie();
            node = node->child[word[i] - 'a'];
        }
        node->end = true;
    }
    string query(string word)
    {
        Trie* node = this;
        for(int i = 0;i < word.size();i++)
        {
            if(node->end == true)
                return word.substr(0, i);
            if(node->child[word[i] - 'a'] == NULL)
                return word;
            node = node->child[word[i] - 'a'];
        }
        return word;
    }
    Trie* child[26] = {NULL};
    bool end = false;
};

class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        Trie root;
        for(auto& word: dict)
            root.insert(word);
        string result = "";
        int start = 0;
        for(int i = 0;i < sentence.size();i++)
        {
            if(sentence[i] == ' ')
            {
                string word = sentence.substr(start, i - start);
                word = root.query(word);
                result = result + word + ' ';
                start = i + 1;
            }
        }
        string word = sentence.substr(start);
        word = root.query(word);
        result = result + word;
        return result;
    }
};
