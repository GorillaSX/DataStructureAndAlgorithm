/*
247. Strobogrammatic Number II
DescriptionHintsSubmissionsDiscussSolution
A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

Find all strobogrammatic numbers that are of length = n.

Example:

Input:  n = 2
Output: ["11","69","88","96"]
*/
class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        vector<string> result;
        string prev(n, ' ');
        find(prev, n, 0, n-1, result);
        return result;
    }
    void find(string prev, int n, int left , int right, vector<string>& result)
    {
        if(left > right)
        {
            result.push_back(prev);
            return ;
        }
        else if(left == right)
        {
            vector<char> choice = {'1', '0', '8'};
            for(int i = 0;i < choice.size();i++)
            {
                prev[left] = choice[i];
                result.push_back(prev);
            }
            return;
        }
        else if(left != right)
        {
            vector<pair<char,char>> choice = {{'1','1'}, {'6', '9'}, {'9','6'}, {'8','8'}};
            if(left != 0)
                choice.push_back(make_pair('0','0'));
            for(int i = 0;i < choice.size();i++)
            {
                prev[left] = choice[i].first;
                prev[right] = choice[i].second;
                find(prev, n, left+1, right-1,result);
            }
        }
    }
};