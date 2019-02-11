/*
320. Generalized Abbreviation
DescriptionHintsSubmissionsDiscussSolution
Write a function to generate the generalized abbreviations of a word. 

Note: The order of the output does not matter.

Example:

Input: "word"
Output:
["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]
*/
class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> result;
        DFS(0, word, "", result);
        return result;        
    }
    void DFS(int index, string word, string prev, vector<string>& result)
    {
        if(index == word.size())
        {
            result.push_back(prev);
            return ;
        }
        DFS(index + 1, word, prev + word[index], result);
        int i = prev.size() - 1;
        while(i>= 0 && isdigit(prev[i]))
            i--;
        if(i == prev.size() - 1)
        {
            DFS(index + 1, word, prev + "1", result);
        }
        else 
        {
            int count = stoi(prev.substr(i+1)) + 1;
            string tmp = (i < 0) ? to_string(count) : prev.substr(0, i+1) + to_string(count);
            DFS(index + 1, word, tmp, result);
        }
    }
};