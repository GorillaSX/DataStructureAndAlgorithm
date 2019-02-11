/*
17. Letter Combinations of a Phone Number
DescriptionHintsSubmissionsDiscussSolution
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.



Example:

Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
*/
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> choice = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> result;
        if(digits.size() == 0)
            return result;
        Generate(digits, 0, choice, "",result);
        return result;
    }
    void Generate(string digits, int index, vector<string>& choice, string current, vector<string>& result)
    {
        if(index == digits.size())
        {
            result.push_back(current);
            return;
        }
        for(auto ch : choice[digits[index]-'0'])
        {
            current.push_back(ch);
            Generate(digits, index+1, choice, current, result);
            current.pop_back();
        }
    }
};