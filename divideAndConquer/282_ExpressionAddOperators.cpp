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
class Solution {
public:
    void dfs(string num, int target, vector<string>& result, string prevString, int startPos, long long cumulativeValue, long long preValue, char ops)
    {
        if(startPos == num.size())
        {
            if(cumulativeValue == target)
                result.push_back(prevString);
            return ;
        }
        
        for(int i = startPos + 1; i <= num.size();i++)
        {
            string newStartString = num.substr(startPos, i - startPos);
            long long newStartValue = stol(newStartString);
            string newStarts = to_string(newStartValue);
            if(newStarts.size() != newStartString.size()) continue;
            dfs(num, target, result, prevString + '+' + newStartString, i, cumulativeValue + newStartValue, newStartValue,  '+');
            dfs(num, target, result, prevString + '-' + newStartString, i, cumulativeValue - newStartValue, newStartValue,  '-');
            dfs(num, target, result, prevString + '*' + newStartString, i, (ops == '-' ? cumulativeValue + preValue - preValue * newStartValue: ( ops == '+' ? cumulativeValue - preValue + preValue * newStartValue : preValue * newStartValue)), preValue * newStartValue, ops);
        }
        
    }
    vector<string> addOperators(string num, int target) {
        vector<string> result;
        if(num.empty()) return result;
        for(int i = 1;i <= num.size();i++)
        {
            string startString = num.substr(0, i);
            long long startValue = stol(startString);
            string startS = to_string(startValue);
            if(startS.size() != startString.size()) continue;
            dfs(num, target, result, startString, i, startValue, startValue, '#');
        }
        return result;
    }
};