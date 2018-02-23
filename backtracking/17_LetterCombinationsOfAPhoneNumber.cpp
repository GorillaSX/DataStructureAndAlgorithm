/*
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.



Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.
*/
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<vector<char>> maps = {{},{},{'a','b','c'},{'d','e','f'},{'g','h','i'},{'j','k','l'},{'m','n','o'},{'p','q','r','s'},{'t','u','v'},{'w','x','y','z'}};
        vector<string> results;
        if(digits == "")
            return results;
        backtracking(maps, digits, "", results);
        return results;
    }
    void backtracking(vector<vector<char>>& maps, string digits, string cur, vector<string>& results)
    {
        if(digits == "")
        {
            results.push_back(cur);
            return ;
        }
        string nextDigits = digits.size() == 1 ? ""  : digits.substr(1);
        for(auto c : maps[digits[0]-'0'])
        {
            cur.push_back(c);
            backtracking(maps, nextDigits, cur, results);
            cur.pop_back();
        }
    }
};