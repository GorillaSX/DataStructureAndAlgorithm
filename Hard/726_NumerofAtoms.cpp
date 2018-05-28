/*
Given a chemical formula (given as a string), return the count of each atom.

An atomic element always starts with an uppercase character, then zero or more lowercase letters, representing the name.

1 or more digits representing the count of that element may follow if the count is greater than 1. If the count is 1, no digits will follow. For example, H2O and H2O2 are possible, but H1O2 is impossible.

Two formulas concatenated together produce another formula. For example, H2O2He3Mg4 is also a formula.

A formula placed in parentheses, and a count (optionally added) is also a formula. For example, (H2O2) and (H2O2)3 are formulas.

Given a formula, output the count of all elements as a string in the following form: the first name (in sorted order), followed by its count (if that count is more than 1), followed by the second name (in sorted order), followed by its count (if that count is more than 1), and so on.

Example 1:
Input: 
formula = "H2O"
Output: "H2O"
Explanation: 
The count of elements are {'H': 2, 'O': 1}.
Example 2:
Input: 
formula = "Mg(OH)2"
Output: "H2MgO2"
Explanation: 
The count of elements are {'H': 2, 'Mg': 1, 'O': 2}.
Example 3:
Input: 
formula = "K4(ON(SO3)2)2"
Output: "K4N2O14S4"
Explanation: 
The count of elements are {'K': 4, 'N': 2, 'O': 14, 'S': 4}.
Note:

All atom names consist of lowercase letters, except for the first character which is uppercase.
The length of formula will be in the range [1, 1000].
formula will only consist of letters, digits, and round parentheses, and is a valid formula as defined in the problem.
*/
class Solution {
public:
    string countOfAtoms(string formula) {
        stack<unordered_map<string, int>> mapStack;
        unordered_map<string, int> map;
        string name = "";
        int count = 0;
        for(int i = 0;i < formula.size();i++)
        {
            if(formula[i] == '(')
            {
                if(name != "")
                    map[name] += (count != 0 ? count : 1);
                name = "";
                count = 0;
                mapStack.push(map);
                map.clear();
            }
            else if(formula[i] == ')')
            {
                if(name != "")
                    map[name] += (count != 0 ? count : 1);
                name = "";
                count  = 0;
                int value = 0;
                while(i + 1 < formula.size() && isdigit(formula[i+1]))
                {
                    i++;
                    value = value * 10 + (formula[i] - '0');
                }
                value = (value != 0 ? value : 1);
                auto oldmap = mapStack.top();
                mapStack.pop();
                for(auto ele : map)
                {
                    map[ele.first] *= value;
                }
                for(auto ele : oldmap)
                {
                    if(map.count(ele.first) != 0)
                        map[ele.first] += ele.second;
                    else 
                        map[ele.first] = ele.second;
                }
            }
            else if(formula[i] >= 'A' && formula[i] <= 'Z')
            {
                if(name != "")
                {
                    map[name] += (count != 0 ? count : 1);
                }
                name = formula[i];
                count = 0;
            }
            else if(formula[i] >= 'a' && formula[i] <= 'z')
            {
                name += formula[i];
            }
            else if(formula[i] >= '0' and formula[i] <= '9')
            {
                count = count * 10 + formula[i] - '0';
            }
        }
        if(name != "")
            map[name] += (count != 0 ? count : 1);
        vector<pair<string, int>> resv; 
        for(auto ele : map)
            resv.push_back(make_pair(ele.first, ele.second));
        sort(resv.begin(), resv.end(), [](const pair<string, int>& lhs, const pair<string,int>& rhs){ return lhs.first < rhs.first;});
        string res = "";
        for(auto p : resv)
            res = res + p.first + (p.second > 1 ? to_string(p.second) : "");
        return res;
    }
};