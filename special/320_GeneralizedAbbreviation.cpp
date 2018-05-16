/*
Write a function to generate the generalized abbreviations of a word.

Example:
Given word = "word", return the following list (order does not matter):
["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]

*/
class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> result;
         if(word == "")
        {
            result.push_back("");
            return result;
        }
        backtracking("", 0, word, result);
        return result; 
    }
    void backtracking(string preword, int index, string word, vector<string>& result)
    {
        int count = 0;
        string pre = "";
        int time = 1;
        for(int i = preword.size() - 1; i>= 0;i--)
        {
           if(isdigit(preword[i]))
           {
               count = (preword[i] - '0') * time + count;
               time *= 10;
           }
           else
           {
               pre = preword.substr(0, i + 1);
               break;
           }
        }
        string first = preword + word[index];
        string two = "";
        if(count == 0)
            two = preword + to_string(1);
        else 
            two = pre + to_string(count + 1);
        if(index == word.size()-1)
        {
            result.push_back(first);
            result.push_back(two);
        }
        else
        {
            backtracking(first, index + 1, word, result);
            backtracking(two, index + 1, word, result);
        }
    }
};