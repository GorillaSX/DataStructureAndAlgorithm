/*
Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to check whether these edges make up a valid tree.

For example:

Given n = 5 and edges = [[0, 1], [0, 2], [0, 3], [1, 4]], return true.

Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]], return false.

Note: you can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.

Valid Tree means there no circle and no isolate nodes or group
*/

class Solution 
{
    public:
    bool validTree(int n, vector<pair<int,int>>& edges)
    {
        vector<int> array;
        for(int i = 0;i < n;i++)
        {
            array.push_back(i);
        }
        for(auto& p : edges)
        {
            int left =  p.first;
            int right = p.second;
            while(array[left] != left)
            {
                left = array[left];
            }
            while(array[right] != right)
            {
                right = array[right];
            }
            if(left != right)
            {
                array[left] = right;
                n--;
            }
            else 
                return false;
        }
        return n == 1 && true;
    }
};
