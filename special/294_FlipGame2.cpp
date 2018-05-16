/*
You are playing the following Flip Game with your friend: Given a string that contains only these two characters: + and -, you and your friend take turns to flip two consecutive "++" into "--". The game ends when a person can no longer make a move and therefore the other person will be the winner.

Write a function to determine if the starting player can guarantee a win.

For example, given s = "++++", return true. The starting player can guarantee a win by flipping the middle "++" to become "+--+".

Follow up:
Derive your algorithm's runtime complexity.
*/
class Solution {
public:
    bool canWin(string s) {
        if(s == "")
            return false;
        unordered_map<string , bool> memory;
        return guaranteWin(s, memory);
    }
    bool guaranteWin(string s, unordered_map<string, bool>& memory)
    {
        if(memory.count(s) != 0)
            return memory[s];
        for(int i = 0;i < s.size() - 1;i++)
        {
            if(s[i] == s[i+1] && s[i] == '+')
            {
                string tmp = s;
                tmp[i] = '-';
                tmp[i+1] = '-';
                if(guaranteWin(tmp, memory) == false)
                {
                    memory[s] = true;
                    return true;
                }
            }
        }
        memory[s] = false;
        return false;
    }
};