/*
Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

You may assume that the given expression is always valid.

Some examples:
"1 + 1" = 2
" 2-1 + 2 " = 3
"(1+(4+5+2)-3)+(6+8)" = 23
*/

//brute force solution
class Solution {
public:
    int calculate(string s) {
        char op = '#';
        int i = 0;
        int left = 0;
        while(i < s.size())
        {
            while(i < s.size() && s[i] == ' ')
                i++;
            int right = 0;
            if(s[i] == '(')
            {
                int tmp = i + 1;
                int count = 1;
                while(count != 0)
                {
                    if(s[tmp] == '(')
                        count++;
                    else if(s[tmp] == ')')
                        count--;
                    tmp++;
                }
                right = calculate(s.substr(i+1, tmp - i + 1 - 3));
                i = tmp;
            }
            else 
            {
                while(i < s.size() && s[i] >= '0' && s[i] <= '9')
                {
                    right = right * 10 + s[i] - '0';
                    i++;
                }
            }
            while(i < s.size() && s[i] == ' ' )
                i++;
            if(i == s.size())
            {
                if(op == '#')
                    return right;
                else 
                    return op == '+' ? left + right : left - right;
            }
            if(op == '#')
            {
                left = right;
                op = s[i];
                i++;
            }
            else 
            {
                left = op == '+' ? left + right : left -right;
                op = s[i];
                i++;
            }
        }       
    }
};