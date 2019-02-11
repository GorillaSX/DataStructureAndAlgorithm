/*
An undirected, connected graph of N nodes (labeled 0, 1, 2, ..., N-1) is given as graph.

graph.length = N, and j != i is in the list graph[i] exactly once, if and only if nodes i and j are connected.

Return the length of the shortest path that visits every node. You may start and stop at any node, you may revisit nodes multiple times, and you may reuse edges.

 

Example 1:

Input: [[1,2,3],[0],[0],[0]]
Output: 4
Explanation: One possible path is [1,0,2,0,3]
Example 2:

Input: [[1],[0,2,4],[1,3,4],[2],[1,2]]
Output: 4
Explanation: One possible path is [0,1,4,2,3]
 

Note:

1 <= graph.length <= 12
0 <= graph[i].length < graph.length
*/
struct State
{
   int cover;
   int cur;
   State(int cv, int cr):cover(cv), cur(cr){}   
};
struct StateHasher
{
    size_t operator()(const State& state) const
    {
        return 123 * state.cover + (state.cover ^ state.cur);
    }
};

struct StateEqual
{
    bool operator()(const State& statea, const State& stateb)const
    {
       return statea.cover == stateb.cover && statea.cur == stateb.cur;
    }
};

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int numOfNode = graph.size();
        unordered_set<State, StateHasher, StateEqual> visited;
        queue<State> BFScurState;
        //Generate start state
        int target = 0;
        for(int i = 0;i < numOfNode;i++)
        {
           target += (1 << i);
           State state(1 << i, i); 
           visited.insert(state);
           BFScurState.push(state);  
        }
        int step = 0;
        while(!BFScurState.empty())
        {
            int size = BFScurState.size();
            for(int i = 0;i < size;i++)
            {
                State tmp = BFScurState.front(); BFScurState.pop();
                if(tmp.cover == target)
                {
                    return step;
                }
                for(auto next : graph[tmp.cur])
                {
                    State nextState(tmp.cover | (1 << next), next);
                    if(visited.count(nextState) == 0)
                    {
                        visited.insert(nextState);
                        BFScurState.push(nextState);
                    } 
                }
            }        
            step++;
        }
    }
};