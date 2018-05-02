/*
Given a 2D board and a list of words from the dictionary, find all words in the board.

Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

For example,
Given words = ["oath","pea","eat","rain"] and board =

[
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]
Return ["eat","oath"].
*/
class Trie 
{
    public:
    Trie(){}
    void insert(string word)
    {
        Trie* node  = this;
        for(int i = 0;i < word.size();i++)
        {
            if(node->child[word[i] - 'a'] == NULL)
                node->child[word[i] - 'a'] = new Trie();
            node = node->child[word[i] - 'a'];
        }
        node->word = word;
    }
    Trie* child[26] = {NULL};
    string word = "";
};

void search(vector<vector<bool>>& visited, unordered_set<string>& result, int i, int j, vector<vector<char>>& board, Trie* node)
{
    int delta[5] = {0, -1, 0, 1, 0};
    int m = board.size();
    int n = m != 0 ? board[0].size() : 0;
    if(node->word != "")
        result.insert(node->word);
    for(int index = 0;index < 4;index++)
    {
        int row = i + delta[index];
        int col = j + delta[index+1];
        if(row >= 0 && row < m && col >=0 && col < n && visited[row][col] == false && node->child[board[row][col] - 'a'] != NULL)
        {
            visited[row][col] = true;
            search(visited, result, row, col, board, node->child[board[row][col] - 'a']);
            visited[row][col] = false;
        }
    }
}
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m = board.size();
        int n = m != 0 ? board[0].size() : 0;
        vector<vector<bool>> visited = vector<vector<bool>>(m, vector<bool>(n, false));
        Trie root;
        for(auto& word : words)
            root.insert(word);
        unordered_set<string> result;
        for(int i = 0;i < m;i++)
        {
            for(int j = 0;j < n;j++)
            {
                if(root.child[board[i][j] - 'a'] != NULL)
                {
                    visited[i][j] = true;
                    search(visited, result, i, j, board, root.child[board[i][j] - 'a']);
                    visited[i][j] = false;
                }
            }
        }
        vector<string> s(result.begin(), result.end());
        return s;
    }
};