/*
We have jobs: difficulty[i] is the difficulty of the ith job, and profit[i] is the profit of the ith job. 

Now we have some workers. worker[i] is the ability of the ith worker, which means that this worker can only complete a job with difficulty at most worker[i]. 

Every worker can be assigned at most one job, but one job can be completed multiple times.

For example, if 3 people attempt the same job that pays $1, then the total profit will be $3.  If a worker cannot complete any job, his profit is $0.

What is the most profit we can make?

Example 1:

Input: difficulty = [2,4,6,8,10], profit = [10,20,30,40,50], worker = [4,5,6,7]
Output: 100 
Explanation: Workers are assigned jobs of difficulty [4,4,6,6] and they get profit of [20,20,30,30] seperately.
Notes:

1 <= difficulty.length = profit.length <= 10000
1 <= worker.length <= 10000
difficulty[i], profit[i], worker[i]  are in range [1, 10^5]
*/

//solution one O((M + N)Log(M + N))
bool myfunction(pair<int,int>& left, pair<int,int>& right)
{
    if(left.first != right.first)
        return left.first < right.first;
    else 
        return left.second > right.second;
}
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int total = 0, curMax = 0;
        vector<pair<int,int>> difficultyAndProfit;
        for(int i = 0;i < difficulty.size();i++)
            difficultyAndProfit.push_back(make_pair(difficulty[i], profit[i]));
        for(int i  =0; i < worker.size(); i++)
            difficultyAndProfit.push_back(make_pair(work[i], 0));
        sort(difficultyAndProfit.begin(), difficultyAndProfit.end(), myfunction);
        for(auto& p : difficultyAndProfit)
        {
            if(p.second == 0)
                total += curMax;
            curMax = max(p.first, curMax);
        }
        return total;
    }
};

//Solution Two
bool myfunction(pair<int,int>& left, pair<int,int>& right)
{
    if(left.first == right.first)
        return left.second > right.second;
    else 
        return left.first < right.first;
}
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int total = 0, curMax = 0;
        vector<pair<int,int>> difficultyAndProfit;
        for(int i = 0;i < difficulty.size();i++)
            difficultyAndProfit.push_back(make_pair(difficulty[i], profit[i]));
        sort(difficultyAndProfit.begin(), difficultyAndProfit.end(), myfunction);
        sort(worker.begin(), worker.end());
        int workerPointer = 0,  diffPointer = 0;
        for(workerPointer = 0; workerPointer < worker.size();workerPointer++)
        {
            while(diffPointer < difficulty.size() && difficultyAndProfit[diffPointer].first <= worker[workerPointer])
            {
                curMax = max(curMax, difficultyAndProfit[diffPointer].second);
                diffPointer++;
            }
            total += curMax;
        }
        return total;
    }
};