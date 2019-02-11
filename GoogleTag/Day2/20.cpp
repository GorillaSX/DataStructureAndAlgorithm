/*
399. Evaluate Division
DescriptionHintsSubmissionsDiscussSolution
Equations are given in the format A / B = k, where A and B are variables represented as strings, and k is a real number (floating point number). Given some queries, return the answers. If the answer does not exist, return -1.0.

Example:
Given a / b = 2.0, b / c = 3.0. 
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? . 
return [6.0, 0.5, -1.0, 1.0, -1.0 ].

The input is: vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries , where equations.size() == values.size(), and the values are positive. This represents the equations. Return vector<double>.

According to the example above:

equations = [ ["a", "b"], ["b", "c"] ],
values = [2.0, 3.0],
queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ]. 
The input is always valid. You may assume that evaluating the queries will result in no division by zero and there is no contradiction.
*/
class Node 
{
public:
    Node(double v): val(v), parent(this){}
    Node* GetParent(void)
    {
        if(parent != this)
        {
            parent = parent->GetParent();
        }
        return parent;
    }
    double val;
    Node* parent;
};

class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        unordered_map<string, Node*> variables;
        for(int i = 0;i < equations.size();i++)
        {
            string left = equations[i].first;
            string right = equations[i].second;
            if(variables.count(left) == 0 && variables.count(right) == 0)
            {
                variables[left]  = new Node( values[i]);
                variables[right] = new Node( 1.0);
                variables[left]->parent = variables[right]; 
            }
            else if(variables.count(left) != 0 && variables.count(right) == 0)
            {
                double value = variables[left]->val / values[i];
                variables[right] = new Node( value);
                variables[right]->parent = variables[left];
            }
            else if(variables.count(left) == 0 && variables.count(right) != 0)
            {
                double value = variables[right]->val * values[i];
                variables[left] = new Node( value);
                variables[left]->parent = variables[right];
            }
            else
            {
                double ratio = (variables[right]->val * values[i]) / variables[left]->val;
                Node* lp = variables[left]->GetParent();
                for(auto var : variables)
                {
                    if((var.second)->GetParent() == lp)
                    {
                        (var.second)->val *= ratio;
                    }
                }
                variables[left]->parent = variables[right];
            }
        }
        vector<double> result;
        for(auto query : queries)
        {
            string left = query.first;
            string right = query.second;
            if(variables.count(left) == 0 || variables.count(right) == 0)
                result.push_back(-1.0);
            else if(variables[left]->GetParent() != variables[right]->GetParent() )
                result.push_back(-1.0);
            else if(variables[left]->GetParent() == variables[right]->GetParent())
                result.push_back(variables[left]->val / variables[right]->val);
        }
        for(auto ele : variables)
        {
            delete ele.second;
        }
        return result;
    }
};





