/*
816. Ambiguous Coordinates
DescriptionHintsSubmissionsDiscussSolution
We had some 2-dimensional coordinates, like "(1, 3)" or "(2, 0.5)".  Then, we removed all commas, decimal points, and spaces, and ended up with the string S.  Return a list of strings representing all possibilities for what our original coordinates could have been.

Our original representation never had extraneous zeroes, so we never started with numbers like "00", "0.0", "0.00", "1.0", "001", "00.01", or any other number that can be represented with less digits.  Also, a decimal point within a number never occurs without at least one digit occuring before it, so we never started with numbers like ".1".

The final answer list can be returned in any order.  Also note that all coordinates in the final answer have exactly one space between them (occurring after the comma.)

Example 1:
Input: "(123)"
Output: ["(1, 23)", "(12, 3)", "(1.2, 3)", "(1, 2.3)"]
Example 2:
Input: "(00011)"
Output:  ["(0.001, 1)", "(0, 0.011)"]
Explanation: 
0.0, 00, 0001 or 00.01 are not allowed.
Example 3:
Input: "(0123)"
Output: ["(0, 123)", "(0, 12.3)", "(0, 1.23)", "(0.1, 23)", "(0.1, 2.3)", "(0.12, 3)"]
Example 4:
Input: "(100)"
Output: [(10, 0)]
Explanation: 
1.0 is not allowed.
*/
class Solution {
public:
    vector<string> ambiguousCoordinates(string S) {
        int len = S.size() - 2;
        vector<string> result;
        for(int l = 1; l < len;l++)
        {
            vector<string> left = GenerateString(S.substr(1, l));
            vector<string> right = GenerateString(S.substr(l + 1, len - l));
            if(left.size() != 0 && right.size() != 0)
            {
                for(auto l : left)
                {
                    for(auto r : right)
                    {
                        string tmp = "(" + l + ", " + r + ")";
                        result.push_back(tmp);
                    }
                }
            }
        }
        return result;

    }
    vector<string> GenerateString(string num)
    {
        vector<string> result;
        if(num.size() == 1)
        {
            result.push_back(num);
            return result;
        }
        if(num[0] == '0' && num.back() == '0')
        {
            return result;
        }
        else if(num[0] == '0' && num.back() != '0')
        {
            string tmp = "0." + num.substr(1);
            result.push_back(tmp);
            return result;
        }
        else if(num[0] != '0' && num.back() == '0')
        {
            result.push_back(num);
            return result;
        }
        else if(num[0] != '0' && num.back() != '0')
        {
            result.push_back(num);
            for(int len = 1; len < num.size();len++)
            {
                string tmp = num.substr(0,len) + "." + num.substr(len);
                result.push_back(tmp);
            }
            return result;
        }
    }
};
