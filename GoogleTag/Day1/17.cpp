/*
481. Magical String
DescriptionHintsSubmissionsDiscussSolution
A magical string S consists of only '1' and '2' and obeys the following rules:

The string S is magical because concatenating the number of contiguous occurrences of characters '1' and '2' generates the string S itself.

The first few elements of string S is the following: S = "1221121221221121122……"

If we group the consecutive '1's and '2's in S, it will be:

1 22 11 2 1 22 1 22 11 2 11 22 ......

and the occurrences of '1's or '2's in each group are:

1 2	2 1 1 2 1 2 2 1 2 2 ......

You can see that the occurrence sequence above is the S itself.

Given an integer N as input, return the number of '1's in the first N number in the magical string S.

Note: N will not exceed 100,000.
*/
class Solution {
public:
    int magicalString(int n) {
        vector<int> magicString;
        magicString.push_back(1);
        int top = 0, bot = 0, oneCount = 0;
        while(top < n)
        {
            if(magicString[top] == 1)
            {
                oneCount++;
                magicString.push_back(magicString[bot] == 1 ? 2 : 1);
                bot++;
            }
            else 
            {
                if(magicString[bot] == 2)
                {
                    magicString.push_back({2,1});
                }    
                else 
                {
                    magicString.push_back({1,2});
                }
                bot+=2;
            }
            top++;
        }
        return count;
    }
};