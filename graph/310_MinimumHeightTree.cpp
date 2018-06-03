/*
For a undirected graph with tree characteristics, we can choose any node as the root. The result graph is then a rooted tree. Among all possible rooted trees, those with minimum height are called minimum height trees (MHTs). Given such a graph, write a function to find all the MHTs and return a list of their root labels.

Format
The graph contains n nodes which are labeled from 0 to n - 1. You will be given the number n and a list of undirected edges (each edge is a pair of labels).

You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.

Example 1 :

Input: n = 4, edges = [[1, 0], [1, 2], [1, 3]]

        0
        |
        1
       / \
      2   3 

Output: [1]
Example 2 :

Input: n = 6, edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]

     0  1  2
      \ | /
        3
        |
        4
        |
        5 

Output: [3, 4]
*/
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        if(n == 1)
        {
            return vector<int>{0};
        }
        unordered_map<int, unordered_set<int>> graph;
        for(auto edge : edges)
        {
            graph[edge.first].insert(edge.second);
            graph[edge.second].insert(edge.first); 
        }
        vector<int> removed ;
        for(auto ele : graph)
        {
            if(ele.second.size() == 1)
            {
                removed.push_back(ele.first);
            }
        }
        while(graph.size() > 2 )
        {
            vector<int> tmp;
            for(auto node : removed)
            {
                int child = *graph[node].begin();
                graph[child].erase(node);
                graph.erase(node);
                if(graph[child].size() == 1)
                    tmp.push_back(child);
            }  
            swap(tmp, removed);
        }
        return removed;
    }
};