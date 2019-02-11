/*
294. Flip Game II
DescriptionHintsSubmissionsDiscussSolution
You are playing the following Flip Game with your friend: Given a string that contains only these two characters: + and -, you and your friend take turns to flip two consecutive "++" into "--". The game ends when a person can no longer make a move and therefore the other person will be the winner.

Write a function to determine if the starting player can guarantee a win.

Example:

Input: s = "++++"
Output: true 
Explanation: The starting player can guarantee a win by flipping the middle "++" to become "+--+".
Follow up:
Derive your algorithm's runtime complexity.
*/
class Solution {
public:
    bool canWin(string s) {
        if(s == "")
            return false;
        unordered_map<string, bool> memo;
        return canWin(s, memo);
    }
    bool canWin(string s, unordered_map<string, bool>& memo)    
    {
        if(memo.count(s) != 0)
            return memo[s];
        bool win = false;
        for(int i = 0;i < s.size() - 1;i++)
        {
            if(s[i] == '+' && s[i] == s[i+1])
            {
                s.replace(i, 2, "--");
                if(!canWin(s))
                {
                    memo[s] = true;
                    return true;
                }
                s.replace(i, 2, "++");
            }
        }       
        memo[s] = win;
        return win;
    }
};