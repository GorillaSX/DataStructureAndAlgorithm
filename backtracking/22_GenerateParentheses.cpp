/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/


class SolutionOne
{
    public:
        vector<string> generateParenthesis(int n)
        {
           unordered_set<string> results; 
           generate(n, "", results);
           return vector<string>(results.begin(), results.end());
        }

        void generate(int n, string cur, unordered_set<string>& results)
        {
            if(n == 0)
            {
                results.insert(cur);
                return;
            }
            for(int i = 0;i <= cur.size();i++)
            {
                string tmp = cur;
                tmp.insert(tmp.begin()+i, "()");
                generate(n - 1, tmp, results);
            }
        }
};

class Solution {
public:
    vector<string> generateParenthesis(int n) {
       unordered_set<string> results;
       generate("", results, 0, 0, n);
       return vector<string>(results.begin(), results.end()); 
    }

    void generate(string cur, unordered_set<string>& results, int left, int right, int max)
    {
        if(cur.size() == 2 * max)
        {
            results.insert(cur);
            return;
        }
        
        if(left < max)
            generate(cur + "(", results, left + 1, right, max);
        if(right < left)
            generate(cur + ")", results, left, right + 1, max);
    }
};