/*
In the "100 game," two players take turns adding, to a running total, any integer from 1..10. The player who first causes the running total to reach or exceed 100 wins.

What if we change the game so that players cannot re-use integers?

For example, two players might take turns drawing from a common pool of numbers of 1..15 without replacement until they reach a total >= 100.

Given an integer maxChoosableInteger and another integer desiredTotal, determine if the first player to move can force a win, assuming both players play optimally.

You can always assume that maxChoosableInteger will not be larger than 20 and desiredTotal will not be larger than 300.

Example

Input:
maxChoosableInteger = 10
desiredTotal = 11

Output:
false

Explanation:
No matter which integer the first player choose, the first player will lose.
The first player can choose an integer from 1 up to 10.
If the first player choose 1, the second player can only choose integers from 2 up to 10.
The second player will win by choosing 10 and get a total = 11, which is >= desiredTotal.
Same with other integers chosen by the first player, the second player will always win.
*/

class Solution {
public:
    int  GetScore(bool player1, int maxChoosableInteger, int desiredTotal, int current, unordered_set<int>& visited, unordered_map<int, int>& scores)
    {
        int state = 0;
        state = player1 ? 1 << 25 : 0;
        for(int i = maxChoosableInteger;i >= 1;i--)
        {
            if(visited.count(i) == 0)
            {
                state += 1 << i;
            }
        }
        if(scores.count(state) != 0)
            return scores[state];
        
        int sum = 0;
        for(int i = maxChoosableInteger;i >= 1; i--)
        {
            if(visited.count(i) == 0)
            {
                if(current + i >= desiredTotal)
                {
                    scores[state] =  player1 ? 10 : -10;
                    return scores[state];
                }
                sum += i;
            }
        }
        int score = player1 ? INT_MIN : INT_MAX;
        if(sum + current < desiredTotal)
        {
            scores[state] = -10;
            return scores[state];
        }
        for(int i = maxChoosableInteger;i >= 1; i--)
        {
            if(visited.count(i) == 0)
            {
                visited.insert(i);
                int theScore = GetScore(!player1, maxChoosableInteger, desiredTotal, current + i, visited, scores);
                score = player1 ? max(score, theScore) : min(score, theScore);
                visited.erase(i);
                if(player1)
                {
                    if(score == 10)
                    {
                        scores[state] = 10;
                        return scores[state];    
                    }
                }
                else
                {
                    if(score == -10)
                    {
                        scores[state] = -10;
                        return scores[state];
                    }
                }
            }
        }
        scores[state] = score;
        return scores[state];
    }
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
       unordered_set<int> visited;
       unordered_map<int, int> scores; 
       int score = GetScore(true, maxChoosableInteger, desiredTotal, 0, visited, scores);
       if(score == 10)
            return true;
        else 
            return false;
    }
};

//solution two 
int format(const vector<bool>& visited)
{
    int state = 0;
    for(int i = 1;i < visited.size();i++)
    {
        if(visited[i] == false)
            state += 1 << i;
    }
    return state;
}

class Solution {
public:
    vector<bool> visited;
    unordered_map<int, bool> maps;
    bool helper(int target)
    {
        int state = format(visited);
        if(target <= 0)
        {
            maps[state] = false;
            return false;
        }
        if(maps.count(state) != 0)
            return maps[state];
        
        for(int i = 1;i < visited.size();i++)
        {
            if(visited[i] == false)
            {
                visited[i] = true;
                if(!helper(target - i))
                {
                    maps[state] = true;
                    visited[i] = false;
                    return true;
                }
                visited[i] = false;
            }
        }
        maps[state] = false;
        return false;
    }
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        int total = ((1 + maxChoosableInteger) * maxChoosableInteger) / 2 ;
        if(total < desiredTotal)
            return false;  
        if(desiredTotal <= 0)
            return true;
        visited = vector<bool>(maxChoosableInteger+1, false);
        return helper(desiredTotal);
    }
};