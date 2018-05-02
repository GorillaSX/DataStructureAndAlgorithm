/*
Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. The valid operators are +, - and *.


Example 1
Input: "2-1-1".

((2-1)-1) = 0
(2-(1-1)) = 2
Output: [0, 2]


Example 2
Input: "2*3-4*5"

(2*(3-(4*5))) = -34
((2*3)-(4*5)) = -14
((2*(3-4))*5) = -10
(2*((3-4)*5)) = -10
(((2*3)-4)*5) = 10
Output: [-34, -14, -10, -10, 10]
*/
class Solution {
public:
    vector<int> calculate(char op, vector<int>&& left, vector<int>&& right)
    {
        vector<int> results;
        for(auto& l : left)
        {
            for(auto& r : right)
            {
                switch(op)
                {
                    case '-':
                        results.push_back(l - r);
                        break;
                    case '+':
                        results.push_back(l + r);
                        break;
                    case '*':
                        results.push_back(l * r);
                        break;
                } 
            }
        }
        return results;
    }
    vector<int> helper(string input)
    {
       int i = 0;
       bool isNumber = true;
       vector<int> results;
       for(i = 0;i < input.size();i++)
       {
           if(input[i] == '-' || input[i] == '+' || input[i] == '*')
           {
               vector<int> tmp;
                tmp = calculate(input[i], helper(input.substr(0, i)), helper(input.substr(i+1)));
               results.insert(results.end(), tmp.begin(), tmp.end());
               isNumber = false;
           }
       } 
       if(isNumber)
            results.push_back(stoi(input));
       return results;
    }
    vector<int> diffWaysToCompute(string input) {
        return helper(input); 
    }
};