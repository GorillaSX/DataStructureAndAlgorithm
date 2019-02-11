/*
562. Longest Line of Consecutive One in Matrix
DescriptionHintsSubmissionsDiscussSolution
Given a 01 matrix M, find the longest line of consecutive one in the matrix. The line could be horizontal, vertical, diagonal or anti-diagonal.
Example:
Input:
[[0,1,1,0],
 [0,1,1,0],
 [0,0,0,1]]
Output: 3
Hint: The number of elements in the given matrix will not exceed 10,000.
*/
class Solution {
public:
    string nextClosestTime(string time) {
       vector<char> numIHave;
       for(int i = 0;i < time.size();i++)
       {
           if(isdigit(time[i]))
                numIHave.push_back(time[i]);
       } 
       sort(numIHave.begin(), numIHave.end());
       if(setUpTime(time, time.size()-1, '9', numIHave))
            return time;
       if(setUpTime(time, time.size()-2, '5', numIHave))
            return time;
       if(setUpTime(time, 1, (time[0] == '2' ? '3' : '9'), numIHave))
            return time;
       if(setUpTime(time, 0, '2', numIHave))
            return time; 
        return time;
    }
    bool setUpTime(string& time, int index, char bound, vector<char>& numIHave)
    {
        auto it = upper_bound(numIHave.begin(), numIHave.end(), time[index]);
        cout << time[index] << endl;
        cout << *it << endl;
        if(it != numIHave.end() && *it <= bound)
        {
            time[index] = *it;
            return true;
        }
        else 
        {
            time[index] = *numIHave.begin();
            return false;
        }
    }
};



















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