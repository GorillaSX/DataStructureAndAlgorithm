/*
Given a time represented in the format "HH:MM", form the next closest time by reusing the current digits. There is no limit on how many times a digit can be reused.

You may assume the given input string is always valid. For example, "01:34", "12:09" are all valid. "1:34", "12:9" are all invalid.

Example 1:

Input: "19:34"
Output: "19:39"
Explanation: The next closest time choosing from digits 1, 9, 3, 4, is 19:39, which occurs 5 minutes later.  It is not 19:33, because this occurs 23 hours and 59 minutes later.
Example 2:

Input: "23:59"
Output: "22:22"
Explanation: The next closest time choosing from digits 2, 3, 5, 9, is 22:22. It may be assumed that the returned time is next day's time since it is smaller than the input time numerically.

*/
class Solution {
public:
    string nextClosestTime(string time) {
        set<int> allowed;
        for(auto c : time)
        {
            if(isdigit(c))
                allowed.insert(c - '0');
        }
        if(setTime(allowed, time, 4, 9))
            return time;
        if(setTime(allowed, time, 3, 5))
            return time;
        int limit = 0;
        if(allowed.count(0) == 1 or allowed.count(1) == 1)
            limit = 9;
        else
            limit = 3;
        if(setTime(allowed, time, 1, limit))
            return time;
        setTime(allowed, time, 0, 2);
        return time;
        
        
        
    }
    bool setTime(set<int>& allowed, string& time,  int index, int limit)
    {
        for(int i = time[index] - '0' + 1;i <= limit ;i++)
        {
            if(allowed.count(i) != 0)
            {
                time[index] = char('0' + i);
                return true;
            }
        }
        for(int i = 0;i <= limit;i++)
        {
            if(allowed.count(i) != 0)
            {
                time[index] = char('0' + i);
                return false;
            }
        }
    }
        
};