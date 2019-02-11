/*
490. The Maze
DescriptionHintsSubmissionsDiscussSolution
There is a ball in a maze with empty spaces and walls. The ball can go through empty spaces by rolling up, down, left or right, but it won't stop rolling until hitting a wall. When the ball stops, it could choose the next direction.

Given the ball's start position, the destination and the maze, determine whether the ball could stop at the destination.

The maze is represented by a binary 2D array. 1 means the wall and 0 means the empty space. You may assume that the borders of the maze are all walls. The start and destination coordinates are represented by row and column indexes.

Example 1

Input 1: a maze represented by a 2D array

0 0 1 0 0
0 0 0 0 0
0 0 0 1 0
1 1 0 1 1
0 0 0 0 0

Input 2: start coordinate (rowStart, colStart) = (0, 4)
Input 3: destination coordinate (rowDest, colDest) = (4, 4)

Output: true
Explanation: One possible way is : left -> down -> left -> down -> right -> down -> right.

Example 2

Input 1: a maze represented by a 2D array

0 0 1 0 0
0 0 0 0 0
0 0 0 1 0
1 1 0 1 1
0 0 0 0 0

Input 2: start coordinate (rowStart, colStart) = (0, 4)
Input 3: destination coordinate (rowDest, colDest) = (3, 2)

Output: false
Explanation: There is no way for the ball to stop at the destination.

Note:
There is only one ball and one destination in the maze.
Both the ball and the destination exist on an empty space, and they will not be at the same position initially.
The given maze does not contain border (like the red rectangle in the example pictures), but you could assume the border of the maze are all walls.
The maze contains at least 2 empty spaces, and both the width and height of the maze won't exceed 100.
*/

class Solution 
{
    public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination)
    {
        int m = maze.size();
        int n = m ? maze[0].size() : 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<vector<int>> memory(m, vector<int>(n, 0));
        return findPath(maze, visited, memory, m, n, start, destination);
    }
    bool findPath(const vector<vector<int>>& maze, vector<vector<bool>>& visited, vector<vector<int>>& memory, int m , int n , vector<int>& start, vector<int>& destination)
    {
        if(memory[start[0]][start[1]] != 0)
            return memory[start[0]][start[1]] == 1;
        if(start[0] == destination[0] && start[1] == destination[1])
        {
            return true;
        }
        int delta[5] = {0, 1 ,0, -1, 0};
        for(int i = 0;i < 4;i++)
        {
            int r =  start[0], c = start[1];
            while(r + delta[i] >= 0 && r + delta[i] < m && c + delta[i+1] >= 0 && c + delta[i+1] < n && maze[r+delta[i]][c+delta[i+1]] == 0)
            {
                r += delta[i];
                c += delta[i+1];
            }
            if(visited[r][c] == false)
            {
                visited[r][c] = true;
                vector<int> s = {r, c};
                if(findPath(maze, visited, memory, m, n, s, destination))
                    return true;
                visited[r][c] = false;
            }
        }
        memory[start[0]][start[1]] = -1;
        return false;
    }
};



