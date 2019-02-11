/*
802. Find Eventual Safe States
DescriptionHintsSubmissionsDiscussSolution
In a directed graph, we start at some node and every turn, walk along a directed edge of the graph.  If we reach a node that is terminal (that is, it has no outgoing directed edges), we stop.

Now, say our starting node is eventually safe if and only if we must eventually walk to a terminal node.  More specifically, there exists a natural number K so that for any choice of where to walk, we must have stopped at a terminal node in less than K steps.

Which nodes are eventually safe?  Return them as an array in sorted order.

The directed graph has N nodes with labels 0, 1, ..., N-1, where N is the length of graph.  The graph is given in the following form: graph[i] is a list of labels j such that (i, j) is a directed edge of the graph.

Example:
Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
Output: [2,4,5,6]
Here is a diagram of the above graph.

Illustration of graph

Note:

graph will have length at most 10000.
The number of edges in the graph will not exceed 32000.
Each graph[i] will be a sorted list of different integers, chosen within the range [0, graph.length - 1].
*/
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int numOfNode = graph.size();
        vector<int> visited(numOfNode, false);
        vector<int> memo(numOfNode, 0);
        vector<int> result;
        for(int i = 0;i < numOfNode;i++)
        {
            visited[i] = true;
            if(checkSafe(graph, visited, memo, i))
                result.push_back(i);
            visited[i] = false;
        }
        return result;
    }
    bool checkSafe(vector<vector<int>>& graph, vector<int>& visited, vector<int>& memo, int node)
    {
        if(memo[node] != 0)
            return memo[node] == 1;
        for(int next : graph[node])
        {
            if(visited[next] == true)
            {
                memo[node] = -1;
                return false;
            }
            if(visited[next] != true)
            {
                visited[next] = true;
                if(!checkSafe(graph, visited, memo, next))
                {
                    visited[next] = false;
                    memo[node] = -1;
                    return false;
                }
                visited[next] = false;
            }
        }
        memo[node] = 1;
        return true;
    }
};