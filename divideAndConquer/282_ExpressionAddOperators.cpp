/*
Given a string that contains only digits 0-9 and a target value, return all possibilities to add binary operators (not unary) +, -, or * between the digits so they evaluate to the target value.

Examples: 
"123", 6 -> ["1+2+3", "1*2*3"] 
"232", 8 -> ["2*3+2", "2+3*2"]
"105", 5 -> ["1*0+5","10-5"]
"00", 0 -> ["0+0", "0-0", "0*0"]
"3456237490", 9191 -> []
Credits:
Special thanks to @davidtan1890 for adding this problem and creating all test cases.
*/
#include <iostream>

class Solution {
public:
    vector<string> calculate(vector<string>&& left, vector<string>&& right)
    {
        vector<string> result;
        for(auto& l : left)
        {
            for(auto& r : right)
            {
                result.push_back(l + "+" + r);
                result.push_back(l + "-" + r);
                result.push_back(l + "*" + r);
            }
        }
        return result;
    }
    vector<string> helper(string num, unordered_map<string, vector<string>>& maps)
    {
        if(maps.count(num) != 0)
            return maps[num];
        vector<string> result;
        result.push_back(num);
        for(int i = 1;i < num.size();i++)
        {
            vector<string>&& tmp = calculate(helper(num.substr(0,i), maps), helper(num.substr(i), maps));
            result.insert(result.end(), tmp.begin(), tmp.end());
        }
        maps[num] = result;
        return result;
    }
    pair<bool,int> evaluate(string num)
    {
        stack<int> ops;
        stack<char> op;
        int i = 0;
        while(i < num.size())
        {
            if(num[i] == '0')
                return make_pair(false, 0);
            int value = 0;
            while(i < nums.size() and num[i] >= '0' and num[i] <= '9')
            {
                value = value * 10 + num[i] - '0';
                i++;
            }
            if(op.size() != 0 and op.top() == '*')
            {
                int left = ops.top(); ops.pop();
                op.pop();
                value *= left;
            }
            if(op.size() != 0 and num[i] != '*')
            {
                char operation = op.top(); op.pop();
                int right = ops.top(); ops.pop();
                int left = ops.top(); ops.pop();
                ops.push(operation == '+' ? left + right : left - right);
            }
            ops.push(value);
            if(i != num.size())
                op.push(num[i]);
        } 
        if(ops.size() != 0)
        {
            char operation = op.top(); op.pop();
            int right = ops.top(); ops.pop();
            int left = ops.top(); ops.pop();
            return make_pair(true, operation == '*' ? left * right : (operation == '+' ? left + right : left - right));
        }
        return make_pair(true, ops.top());
    }
    vector<string> addOperators(string num, int target) {
        vector<string> result;
        unordered_map<string, vector<string>> maps;
        result = helper(num, maps);
        return result; 
    }
};