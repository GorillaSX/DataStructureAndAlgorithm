/*
A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

Find all strobogrammatic numbers that are of length = n.

For example,
Given n = 2, return ["11","69","88","96"].
*/

class Solution 
{
    public:
    vector<string> findStrobogrammatic(int n)
    {
        return find(n, true);
    }
    vector<string> find(int n, bool zero)
    {
        if(n == 1)
        {
            vector<string> res = {"1", "0", "8"};
            return res;
        }
        else if(n == 2)
        {
            vector<string> res = {"11",  "88", "69", "96"};
            if(zero)
                return res;
            else
            {
                res.push_back("00");
                return res;
            }

        }
        else
        {
            vector<string> res;
            vector<string> Got = find(n-2, false);
            for(auto str : Got)
            {
                string tmp = "1" + str + "1";
                res.push_back(tmp);
                tmp = "8" + str + "8";
                res.push_back(tmp);
                tmp = "6" + str + "9";
                res.push_back(tmp);
                tmp = "9" + str + "6";
                res.push_back(tmp);
                if(!zero)
                {
                    tmp = "0" + str + "0";
                    res.push_back(tmp);
                }
            }
            return res;
        }
    }
};
