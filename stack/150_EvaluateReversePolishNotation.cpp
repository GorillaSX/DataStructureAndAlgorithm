/*
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
*/
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> tmpResults;
        for(auto& str : tokens)
        {
           if(str != "*" && str != "+" && str != "-" && str != "/")
           {
               tmpResults.push(stoi(str));
           } 
           else 
           {
               int right = tmpResults.top();
               tmpResults.pop();
               int left = tmpResults.top();
               tmpResults.pop();    
                   if(str == "+") 
                        tmpResults.push(left + right);
                    else if(str == "/")
                        tmpResults.push(left / right);
               else if(str == "*")
                        tmpResults.push(left * right);
               else if(str == "-")
                        tmpResults.push(left - right);   
               
           } 
        }
        return tmpResults.top();
    }
};