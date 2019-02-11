/*
838. Push Dominoes
DescriptionHintsSubmissionsDiscussSolution
There are N dominoes in a line, and we place each domino vertically upright.

In the beginning, we simultaneously push some of the dominoes either to the left or to the right.



After each second, each domino that is falling to the left pushes the adjacent domino on the left.

Similarly, the dominoes falling to the right push their adjacent dominoes standing on the right.

When a vertical domino has dominoes falling on it from both sides, it stays still due to the balance of the forces.

For the purposes of this question, we will consider that a falling domino expends no additional force to a falling or already fallen domino.

Given a string "S" representing the initial state. S[i] = 'L', if the i-th domino has been pushed to the left; S[i] = 'R', if the i-th domino has been pushed to the right; S[i] = '.', if the i-th domino has not been pushed.

Return a string representing the final state. 

Example 1:

Input: ".L.R...LR..L.."
Output: "LL.RR.LLRRLL.."
Example 2:

Input: "RR.L"
Output: "RR.L"
Explanation: The first domino expends no additional force on the second domino.
Note:

0 <= N <= 10^5
String dominoes contains only 'L', 'R' and '.'
*/

class Solution {
public:
    string pushDominoes(string dominoes) {
        queue<int> States;
        for(int i = 0;i < dominoes.size();i++)
        {
            if(dominoes[i] != '.')
                States.push(i);
        }
        while(!States.empty())
        {
            int size = States.size();
            string tmp = dominoes;
            for(int i = 0;i < size;i++)
            {
                int pos = States.front();
                States.pop();
                if(tmp[pos] == 'L' && (pos > 0 && tmp[pos-1] == '.') && (pos - 2 < 0 or tmp[pos-2] != 'R'))
                {
                    dominoes[pos-1] = 'L';
                    States.push(pos - 1);
                }
                else if(tmp[pos] == 'R' && (pos < dominoes.size() - 1 && tmp[pos+1] == '.' && (pos + 2 == dominoes.size() or tmp[pos + 2] != 'L')))
                {
                    dominoes[pos + 1] = 'R';
                    States.push(pos + 1);
                }
            }
        }
        return dominoes;
    }
};