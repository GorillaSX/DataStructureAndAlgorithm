/*
There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

For example:

2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.

2, [[1,0],[0,1]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

Note:
The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.
*/

class Solution 
{
    public:
    bool canFinish(int numCourses, vector<pair<int,int>>& prerequisites)
    {
        unordered_map<int, pair<int, vector<int>>> adj;
        for(auto & p : prerequisites)
        {
            int in = p.second;
            int out = p.first;
            if(adj.count(in) == 0)
                adj[in].first = 0;
            if(adj.count(out) == 0)
                adj[out].first = 0;
            adj[in].second.push_back(out);
            adj[out].first++;
        }
        queue<int> start;
        for(auto & ele : adj)
        {
            if(ele.second.first == 0)
                start.push(ele.first);
        }

        while(start.size() != 0)
        {
            int in = start.front();
            start.pop();
            for(auto& out : adj[in].second)
            {
                adj[out].first--;
                if(adj[out].first == 0)
                    start.push(out);
            }
            adj.erase(in);
        }
        if(adj.size() != 0)
            return false;
        else
            return true;
    }
};