/*
Given a list of daily temperatures, produce a list that, for each day in the input, tells you how many days you would have to wait until a warmer temperature. If there is no future day for which this is possible, put 0 instead.

For example, given the list temperatures = [73, 74, 75, 71, 69, 72, 76, 73], your output should be [1, 1, 4, 2, 1, 1, 0, 0].

Note: The length of temperatures will be in the range [1, 30000]. Each temperature will be an integer in the range [30, 100].


*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(), 0);
        if(temperatures.size() == 0)
            return result;
        stack<pair<int, int>> temper;
        for(int i = 0;i < temperatures.size();i++)
        {
            while(temper.size() != 0 and temper.top().first < temperatures[i])
            {
                result[temper.top().second] = i - temper.top().second;
                temper.pop();
            }
                temper.push(make_pair(temperatures[i], i));   
        }
        return result;
    }
};