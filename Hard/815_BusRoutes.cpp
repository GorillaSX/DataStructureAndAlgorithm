/*
815. Bus Routes
DescriptionHintsSubmissionsDiscussSolution
We have a list of bus routes. Each routes[i] is a bus route that the i-th bus repeats forever. For example if routes[0] = [1, 5, 7], this means that the first bus (0-th indexed) travels in the sequence 1->5->7->1->5->7->1->... forever.

We start at bus stop S (initially not on a bus), and we want to go to bus stop T. Travelling by buses only, what is the least number of buses we must take to reach our destination? Return -1 if it is not possible.

Example:
Input: 
routes = [[1, 2, 7], [3, 6, 7]]
S = 1
T = 6
Output: 2
Explanation: 
The best strategy is take the first bus to the bus stop 7, then take the second bus to the bus stop 6.
Note:

1 <= routes.length <= 500.
1 <= routes[i].length <= 500.
0 <= routes[i][j] < 10 ^ 6.
*/

//One side BFS
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        if(S == T)
            return 0;
        unordered_map<int, unordered_set<int>> stops;
        for(int i = 0;i < routes.size();i++)
        {
           for(auto n : routes[i])
                stops[n].insert(i);
        }   
        if(stops.count(T) == 0)
            return -1;
        unordered_set<int> visited;
        visited.insert(S);
        queue<int> start;
        start.push(S);
        int steps = 0;
        while(!start.empty())
        {
            int size = start.size();
            for(int i = 0;i < size;i++)
            {
                int sta = start.front();
                start.pop();
                for(auto bus : stops[sta])
                {
                   for(auto s : routes[bus])
                   {
                       if(s == T)
                       {
                           return steps + 1;
                       }
                       if(visited.count(s) == 0)
                       {
                          visited.insert(s);
                          start.push(s);  
                       }
                   } 
                }
            } 
            steps++;
        }
        
        return -1;
    }
};

//Two Side BFS
class BFS
{
    public:
    BFS(unordered_map<int, unordered_set<int>>& stops, vector<vector<int>>& routes, int start):m_stops(stops), m_routes(routes)
    {
        toVisit.push(start);
        visited.insert(start);

    }
    bool moveForward(BFS& destination)
    {
        int size = toVisit.size();
        for(int i = 0;i < size;i++)
        {
            int station = toVisit.front();
            toVisit.pop();
            for(auto bus : m_stops[station])
            {
                for(auto nextStation: m_routes[bus])
                {
                    if(destination.visited.count(nextStation))
                        return true;
                    if(visited.count(nextStation) == 0)
                    {
                        visited.insert(nextStation);
                        toVisit.push(nextStation);
                    }
                }
            }
        }
        return false;
    }
    unordered_map<int, unordered_set<int>>& m_stops;
    vector<vector<int>>& m_routes;
    queue<int> toVisit;
    unordered_set<int> visited;
};

class Solution 
{
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T)
    {
        if(S == T)
            return 0;
        unordered_map<int, unordered_set<int>> stops;
        for(int i = 0;i < routes.size();i++)
        {
            for(auto n : routes[i])
                stops[n].insert(i);
        }
        if(stops.count(T) == 0)
            return -1;
        int steps = 0;
        BFS start(stops, routes, S);
        BFS end(stops, routes, T);
        while(start.toVisit.size() != 0 || end.toVisit.size() != 0)
        {
            if(start.moveForward(end))
                return steps + 1;
            steps++;
            if(end.moveForward(start))
                return steps + 1;
            steps++;
        }
        return -1;
    }
};