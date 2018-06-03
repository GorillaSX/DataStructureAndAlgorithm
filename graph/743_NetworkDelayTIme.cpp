/*
There are N network nodes, labelled 1 to N.

Given times, a list of travel times as directed edges times[i] = (u, v, w), where u is the source node, v is the target node, and w is the time it takes for a signal to travel from source to target.

Now, we send a signal from a certain node K. How long will it take for all nodes to receive the signal? If it is impossible, return -1.

Note:
N will be in the range [1, 100].
K will be in the range [1, N].
The length of times will be in the range [1, 6000].
All edges times[i] = (u, v, w) will have 1 <= u, v <= N and 1 <= w <= 100.
*/
//BFS Solution
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        unordered_map<int, vector<pair<int,int>>> adjTable;
        for(auto time : times)
            adjTable[time[0]].push_back(make_pair(time[1], time[2]));
        queue<int> parents;
        parents.push(K);
        unordered_map<int, int> travelTime;
        travelTime[K] = 0;
        while(!parents.empty())
        {
            int parent = parents.front();
            parents.pop();
            for(auto child : adjTable[parent])
            {
                if((travelTime.count(child.first) == 0) or (travelTime[parent] + child.second < travelTime[child.first]))
                {
                    parents.push(child.first);
                    travelTime[child.first] = child.second + travelTime[parent];
                }
            }
        }
        if(travelTime.size() != N)
            return -1;
        int time = 0;
        for(auto ele : travelTime)
        {
           time = max(time, ele.second); 
        }
        return time;
    }
};
//Dijkstra Algorithm 
O(N*N)
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        unordered_map<int, vector<pair<int,int>>> adjTable;
        for(auto time : times)
            adjTable[time[0]].push_back(make_pair(time[1], time[2]));
        unordered_map<int, int> travelTime;
        unordered_map<int, int> visited; 
        travelTime[K] = 0;
        while(true)
        {
            if(travelTime.size() == 0)
                break;
            int parent  = (travelTime.begin())->first;
            for(auto node : travelTime)
            {
                if(node.second < travelTime[parent])
                    parent = node.first;
            }
            visited[parent] = travelTime[parent];
            for(auto child : adjTable[parent])
            {
                if((visited.count(child.first) == 0 && travelTime.count(child.first) == 0) || (travelTime.count(child.first) != 0 && travelTime[child.first] > travelTime[parent] + child.second))
                   {
                       travelTime[child.first] = travelTime[parent] + child.second;
                   }
            }
            travelTime.erase(parent);
        }
        if(visited.size() != N)
            return -1;
        int time = 0;
        for(auto n : visited)
        {
            time = max(time, n.second);
        }
        return time;

    }
};
//heap 
class comp 
{
    public:
    bool operator()(const pair<int,int>& lhs, const pair<int,int>& rhs)  const 
    {
        return lhs.first > rhs.first;
    } 
};
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        unordered_map<int, vector<pair<int,int>>> adjTable;
        for(auto time : times)
            adjTable[time[0]].push_back(make_pair(time[1], time[2]));
        typedef priority_queue<pair<int,int>, vector<pair<int,int>>, comp> mypq; 
        mypq travelTime;
        travelTime.push(make_pair(0, K));
        unordered_map<int, int> visited; 
        while(true)
        {
            if(travelTime.size() == 0)
                break;
            auto parent = travelTime.top();
            travelTime.pop();
            if(visited.count(parent.second) != 0)
            {
                continue;
            }
            visited[parent.second] = parent.first;
            for(auto child : adjTable[parent.second])
            {
                travelTime.push(make_pair(parent.first + child.second, child.first));
            }
        }
        if(visited.size() != N)
            return -1;
        int time = 0;
        for(auto n : visited)
        {
            time = max(time, n.second);
        }
        return time;

    }
};