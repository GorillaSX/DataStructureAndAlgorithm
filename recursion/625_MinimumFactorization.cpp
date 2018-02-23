/*
Given a positive integer a, find the smallest positive integer b whose multiplication of each digit equals to a.

If there is no answer or the answer is not fit in 32-bit signed integer, then return 0.

Example 1
Input:

48 
Output:
68
Example 2
Input:

15
Output:
35
*/
class Solution {
public:
    int smallestFactorization(int a) {
        long long small =  smallest(a);
        return small > 0 && small < INT_MAX ? (int)small : 0;
    }
    long long smallest(int a) {
        if(a < 10)
            return a;
        for(int i = 9;i >= 2;i--)
        {
            if(a % i == 0)
            {
                long long  small = smallest(a / i);
                if(small > 0 && small < INT_MAX)
                {
                    return small * 10 + i;
                }
            }
        }
        return 0;
    }
};