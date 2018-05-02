/*
Given an expression such as expression = "e + 8 - a + 5" and an evaluation map such as {"e": 1} (given in terms of evalvars = ["e"] and evalints = [1]), return a list of tokens representing the simplified expression, such as ["-1*a","14"]

An expression alternates chunks and symbols, with a space separating each chunk and symbol.
A chunk is either an expression in parentheses, a variable, or a non-negative integer.
A variable is a string of lowercase letters (not including digits.) Note that variables can be multiple letters, and note that variables never have a leading coefficient or unary operator like "2x" or "-x".
Expressions are evaluated in the usual order: brackets first, then multiplication, then addition and subtraction. For example, expression = "1 + 2 * 3" has an answer of ["7"].

The format of the output is as follows:

For each term of free variables with non-zero coefficient, we write the free variables within a term in sorted order lexicographically. For example, we would never write a term like "b*a*c", only "a*b*c".
Terms have degree equal to the number of free variables being multiplied, counting multiplicity. (For example, "a*a*b*c" has degree 4.) We write the largest degree terms of our answer first, breaking ties by lexicographic order ignoring the leading coefficient of the term.
The leading coefficient of the term is placed directly to the left with an asterisk separating it from the variables (if they exist.)  A leading coefficient of 1 is still printed.
An example of a well formatted answer is ["-2*a*a*a", "3*a*a*b", "3*b*b", "4*a", "5*c", "-6"] 
Terms (including constant terms) with coefficient 0 are not included.  For example, an expression of "0" has an output of [].
Examples:

Input: expression = "e + 8 - a + 5", evalvars = ["e"], evalints = [1]
Output: ["-1*a","14"]

Input: expression = "e - 8 + temperature - pressure",
evalvars = ["e", "temperature"], evalints = [1, 12]
Output: ["-1*pressure","5"]

Input: expression = "(e + 8) * (e - 8)", evalvars = [], evalints = []
Output: ["1*e*e","-64"]

Input: expression = "7 - 7", evalvars = [], evalints = []
Output: []

Input: expression = "a * b * c + b * a * c * 4", evalvars = [], evalints = []
Output: ["5*a*b*c"]

Input: expression = "((a - b) * (b - c) + (c - a)) * ((a - b) + (b - c) * (c - a))",
evalvars = [], evalints = []
Output: ["-1*a*a*b*b","2*a*a*b*c","-1*a*a*c*c","1*a*b*b*b","-1*a*b*b*c","-1*a*b*c*c","1*a*c*c*c","-1*b*b*b*c","2*b*b*c*c","-1*b*c*c*c","2*a*a*b","-2*a*a*c","-2*a*b*b","2*a*c*c","1*b*b*b","-1*b*b*c","1*b*c*c","-1*c*c*c","-1*a*a","1*a*b","1*a*c","-1*b*c"]

*/
vector<string> split(string term)
{
    vector<string> eles;
    if(term == "")
        return eles;
    int last = 0;
    for(int i = 0;i < term.size();i++)
    {
        if(term[i] == '*')
        {
            eles.push_back(term.substr(last, i - last));
            last = i + 1;
        }
    }
    eles.push_back(term.substr(last));
    return eles;
}
    
bool myfunction(pair<int, string>& left, pair<int,string>& right)
{
    vector<string> l = split(left.second);
    vector<string> r = split(right.second);
    if(l.size() != r.size())
        return l.size() > r.size();
    else 
    {
        for(int i = 0;i < l.size();i++)
        {
            if(l[i] != r[i])
                return l[i] < r[i];
        }
        return false;
    }
}

class Solution {
public:
    unordered_map<string,int> maps;
    vector<string> basicCalculatorIV(string expression, vector<string>& evalvars, vector<int>& evalints)
    {
        for(int i = 0;i < evalvars.size();i++)
            maps[evalvars[i]] = evalints[i];
        vector<pair<int, string>> tmp = basicCalculatorIV(expression);
        sort(tmp.begin(), tmp.end(), myfunction);
        vector<string> result;
        for(auto& ele : tmp)
        {
            if(ele.first != 0)
            {
                string r = "";
                r += to_string(ele.first);
                if(ele.second != "")
                r  = r + "*"+  ele.second; 
                result.push_back(r);
            }
        }
        return result;
    }
    vector<pair<int, string>> add(vector<pair<int, string>>& left, vector<pair<int, string>>& right)
{
        vector<pair<int, string>> result(left.begin(), left.end());
        for(auto& r : right)
        {
            int i = 0, size = result.size();
            for(i = 0;i < size;i++)
            {
                auto& l = result[i];
                if(r.second == l.second)
                {
                   l.first =  l.first  + r.first;
                   if(l.first == 0)
                        l.second = "";
                   break;
                }
            }
            if(i == size)
                result.push_back(r);
        }
        return result;
}
string sortATerm(string term)
{
    vector<string> eles;
    int last = 0;
    for(int i = 0;i < term.size();i++)
    {
        if(term[i] == '*')
        {
            eles.push_back(term.substr(last, i - last));
            last = i + 1;
        }
    }
    eles.push_back(term.substr(last));
    sort(eles.begin(), eles.end());
    string result = "";
    for(auto& s : eles)
        result = result + s + "*";
    return result.substr(0, result.size() - 1);
}

vector<pair<int, string>> multiply(vector<pair<int, string>>&left, vector<pair<int,string>>& right)
{
    stack<vector<pair<int, string>>> Mstack;
    for(auto& r: right)
    {
        vector<pair<int, string>> tmp(left.begin(), left.end());
        for(auto& l : tmp)
        {
            l.first = l.first * r.first;
            

            if(l.second != "" and r.second != "")
                l.second = l.second + "*" +  r.second; 
            else if(l.second == "" and r.second != "")
                l.second = r.second;
                
            
            l.second = sortATerm(l.second);
        }
        Mstack.push(tmp);
    }
    while(Mstack.size() > 1)
    {
        vector<pair<int,string>> r = Mstack.top();Mstack.pop();
        vector<pair<int,string>> l = Mstack.top();Mstack.pop();
        Mstack.push(add(l, r));
    }
    return Mstack.top();
}
void multiply(int n, vector<pair<int, string>>& value)
{
    for(auto& ele : value)
    {
        ele.first = ele.first * n;
    }
}

vector<pair<int,string>> translate(string expression)
{
    vector<pair<int,string>> results;
    if(expression[0] >= '0' and expression[0] <= '9')
    {
        int value = 0;
        for(int i = 0;i < expression.size();i++)
        {
            value = value * 10 + expression[i] - '0';
        }
        results.push_back(make_pair(value, ""));
    }
    else 
    {
        if(maps.count(expression) != 0)
            results.push_back(make_pair(maps[expression], ""));
        else
            results.push_back(make_pair(1, expression));
    }
    return results;
}


    vector<pair<int, string>> basicCalculatorIV(string expression) {
            stack<vector<pair<int, string>>> mystack;
            char sign = '+';
            vector<pair<int, string>> value;
            for(int i = 0;i < expression.size();i++)
            {
                if(expression[i] == ' ' )
                    continue;
                if(expression[i] == '(')
                {
                    int tmp = i + 1;
                    int count = 1;
                    while(count != 0)
                    {
                        if(expression[tmp] == '(')
                            count++;
                        else if(expression[tmp] == ')')
                            count--;
                        tmp++;
                    }
                    value = basicCalculatorIV(expression.substr(i+1, tmp - i + 1 - 3));
                    i = tmp - 1;
                }
                else if((expression[i] >= '0' and expression[i] <= '9') or (expression[i] >= 'a' and expression[i] <= 'z'))
                {
                    int tmp = i + 1;
                    while(tmp < expression.size() and expression[tmp] != ' ')
                        tmp++;
                    value = translate(expression.substr(i, tmp - i));
                    i = tmp - 1;
                }
                else if(expression[i] == '+' or expression[i] == '-' or expression[i] == '*')
                {
                    if(sign == '+')
                    {
                        mystack.push(value);
                    }
                    else if(sign == '-')
                    {
                        multiply(-1, value);
                        mystack.push(value);
                    }
                    else if(sign == '*')
                    {
                        vector<pair<int, string>> left = mystack.top(); mystack.pop();
                        mystack.push(multiply(left, value));
                    }
                    sign = expression[i];
                }
            }
            if(sign == '+')
            {
                mystack.push(value);
            }
            else if(sign == '-')
            {
                multiply(-1, value);
                mystack.push(value);
            }
            else if(sign == '*')
            {
                vector<pair<int, string>> left = mystack.top(); mystack.pop();
                mystack.push(multiply(left, value));
            }
            while(mystack.size() > 1)
            {
                vector<pair<int, string>> right = mystack.top(); mystack.pop();
                vector<pair<int, string>> left  = mystack.top(); mystack.pop();
                mystack.push(add(left, right));
            }
            return mystack.top();
    }   
};