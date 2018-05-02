/*
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, two is written as II in Roman numeral, just two one's added together. Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given an integer, convert it to a roman numeral. Input is guaranteed to be within the range from 1 to 3999.

Example 1:

Input: 3
Output: "III"
Example 2:

Input: 4
Output: "IV"
Example 3:

Input: 9
Output: "IX"
Example 4:

Input: 58
Output: "LVIII"
Explanation: C = 100, L = 50, XXX = 30 and III = 3.
Example 5:

Input: 1994
Output: "MCMXCIV"
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
*/
class Solution {
public:
    string intToRoman(int num) {
        unordered_map<int, string> maps({{1, "I"}, {5, "V"}, {10, "X"}, {50, "L"}, {100, "C"}, {500, "D"}, {1000, "M"}});
        string result = "";
        int base = 1;
        while(num > 0)
        {
            int times = num % 10;   
            string one = maps[base];
            string five = maps[base * 5];
            string ten = maps[base * 10];
            string tmp = "";
            if(times == 5)
                tmp =  five;
            else if(times == 4)
                tmp =  one + five;
            else if(times == 9)
                tmp =  one + ten;
            else 
            {
                if(times > 5)
                {
                    tmp += five;
                    times -= 5;
                }
                for(int i = 0;i < times;i++)
                {
                    tmp += one;
                }
            }
            result = tmp + result;
            base *= 10; 
            num /= 10;
        }
        return result;
    }
};