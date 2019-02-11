/*
357. Count Numbers with Unique Digits
DescriptionHintsSubmissionsDiscussSolution
Given a non-negative integer n, count all numbers with unique digits, x, where 0 ≤ x < 10n.

Example:
Given n = 2, return 91. (The answer should be the total numbers in the range of 0 ≤ x < 100, excluding [11,22,33,44,55,66,77,88,99])

Credits:
Special thanks to @memoryless for adding this problem and creating all test cases.
*/
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0)
            return 1;
        else if(n == 1)
            return 10;
        else if(n == 2)
            return 91;
        else 
        {
            int count = 91;
            int size = 3;
            int base = 81, multi = 8;
            while(size <= n)
            {
                count = count + base * multi;
                base *= multi;
                multi--;
                size++;
            }
            return count;
        }
    }
};