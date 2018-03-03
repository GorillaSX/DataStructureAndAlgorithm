/*
Given a char array representing tasks CPU need to do. It contains capital letters A to Z where different letters represent different tasks.Tasks could be done without original order. Each task could be done in one interval. For each interval, CPU could finish one task or just be idle.

However, there is a non-negative cooling interval n that means between two same tasks, there must be at least n intervals that CPU are doing different tasks or just be idle.

You need to return the least number of intervals the CPU will take to finish all the given tasks.

Example 1:
Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8
Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.
*/

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> dict;
        int count = 0;
        for(auto c : tasks)
        {
            dict[c]++;
            count = max(count, dict[c]);
        }
        int res = (count - 1) * (n + 1);
        for(auto e : dict) 
            if(e.second == count)
                res++;
        return max((int)tasks.size(), res);
    }
};
//Solution two, using priority_queue
class mycomparison
{
    public:
    bool operator()(const pair<char, int>& lhs, const pair<char, int>& rhs) const
    {
        return lhs.second < rhs.second;
    }
};
class Solution 
{
    public:
    int leastInterval(vector<char>& tasks, int n)
    {
        unordered_map<char, int> dict;
        typedef priority_queue<pair<char,int>, vector<pair<char,int>>, mycomparison> mypq;
        mypq pq;
        for(auto c : tasks)
        {
            dict[c]++;
        }
        for(auto& e : dict)
        {
            pair<char,int> tmp(e.first, e.second);
            pq.push(tmp);
        }
        int count = 0;
        while(true)
        {

            vector<pair<char, int>> tmpv;
            for(int i = 0;i <=n ; i++)
            {
                if(pq.empty() && tmpv.size() == 0)
                    return count;
                else if(pq.empty() && tmpv.size() != 0)
                {
                    count++;
                }
                else if(!pq.empty())
                {
                    pair<char, int> tmp =pq.top();
                    pq.pop();
                    tmp.second--;
                    if(tmp.second != 0)
                        tmpv.push_back(tmp);
                    count++;
                }
            }
            for(auto p : tmpv)
            {
                pq.push(p);
            }
        }
    }
};