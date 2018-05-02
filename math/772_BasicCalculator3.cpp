/*
Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

The expression string contains only non-negative integers, +, -, *, / operators , open ( and closing parentheses ) and empty spaces . The integer division should truncate toward zero.

You may assume that the given expression is always valid. All intermediate results will be in the range of [-2147483648, 2147483647].

Some examples:

"1 + 1" = 2
" 6-4 / 2 " = 4
"2*(5+5*2)/3+(6/2+8)" = 21
"(2+6* 3+5- (3*14/7+2)*5)+3"=-12
*/
class Solution {
public:
    int calculate(string s) {
        int i = 0;
        stack<int> nums;
        stack<char> ops;
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
                while(ops.size() != 0)
                {
                    int left = nums.top(); nums.pop();
                    char op = ops.top(); ops.pop();
                    switch(op)
                    {
                        case '+':
                            left = left + right;
                            break;
                        case '-':
                            left = left - right;
                            break;
                        case '*':
                            left = left * right;
                            break;
                        case '/':
                            left = left / right;
                            break;
                    }
                    right = left;
                }
                nums.push(right);
                return nums.top();
                
            }
            if(ops.size() == 0)
            {
                nums.push(right);
                ops.push(s[i]);
                i++;
            }
            else 
            {
                if(ops.top() == '*' or ops.top() == '/')
                {
                    char op = ops.top(); ops.pop();
                    int left = nums.top(); nums.pop();
                    right = op == '*' ? left * right : left / right;
                }
                if(s[i] == '+' or s[i] == '-')
                {
                    nums.push(right);
                    if(ops.size() != 0)
                    {
                        char op = ops.top(); ops.pop();
                        int r = nums.top(); nums.pop();
                        int l = nums.top(); nums.pop();
                        nums.push((op == '+' ? l + r : l - r));
                    }
                    ops.push(s[i]);
                }
                else 
                {
                    nums.push(right);
                    ops.push(s[i]);
                }
                i++;
            }
        }       
    }
};