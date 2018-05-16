/*
By now, you are given a secret signature consisting of character 'D' and 'I'. 'D' represents a decreasing relationship between two numbers, 'I' represents an increasing relationship between two numbers. And our secret signature was constructed by a special integer array, which contains uniquely all the different number from 1 to n (n is the length of the secret signature plus 1). For example, the secret signature "DI" can be constructed by array [2,1,3] or [3,1,2], but won't be constructed by array [3,2,4] or [2,1,3,4], which are both illegal constructing special string that can't represent the "DI" secret signature.

On the other hand, now your job is to find the lexicographically smallest permutation of [1, 2, ... n] could refer to the given secret signature in the input.

Example 1:
Input: "I"
Output: [1,2]
Explanation: [1,2] is the only legal initial spectial string can construct secret signature "I", where the number 1 and 2 construct an increasing relationship.
Example 2:
Input: "DI"
Output: [2,1,3]
Explanation: Both [2,1,3] and [3,1,2] can construct the secret signature "DI", 
but since we want to find the one with the smallest lexicographical permutation, you need to output [2,1,3]
Note:

The input string will only contain the character 'D' and 'I'.
The length of input string is a positive integer and will not exceed 10,000
*/
class Solution {
public:
    vector<int> findPermutation(string s) {
        vector<int> result;
        if(s.size() == 0)
            return result;
        int num =  1;
        int start = 0;
        while(start < s.size())
        {
            int tmp = start;
            char op = s[tmp];
            if(op == 'I')
            {
                while(tmp < s.size() && s[tmp] == 'I')
                {
                    result.push_back(num);
                    num++;
                    tmp++;
                }
                start = tmp;
            }
            else
            {
                while(tmp < s.size() && s[tmp] == op)
                    tmp++;
                
                int size = tmp - start + 1;
                int startnum = num + size - 1;
                for(int i = startnum;i >= num;i--)
                    result.push_back(i);
                
                if(tmp == s.size())
                {
                    return result;
                }
                num = startnum + 1;
                start = tmp + 1;
            }
        }
        result.push_back(num);
        return result;
    }
};