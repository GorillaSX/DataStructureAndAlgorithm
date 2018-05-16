/*
Given a list of points that form a polygon when joined sequentially, find if this polygon is convex (Convex polygon definition).

Note:

There are at least 3 and at most 10,000 points.
Coordinates are in the range -10,000 to 10,000.
You may assume the polygon formed by given points is always a simple polygon (Simple polygon definition). In other words, we ensure that exactly two edges intersect at each vertex, and that edges otherwise don't intersect each other.
Example 1:

[[0,0],[0,1],[1,1],[1,0]]

Answer: True

Explanation:
Example 2:

[[0,0],[0,10],[10,10],[10,0],[5,5]]

Answer: False

Explanation:
*/
class Solution {
public:
   
    
    bool isConvex(vector<vector<int>>& points) {
        if(points.size() < 3)
            return false;
        else if(points.size() == 3)
            return true;
        else
        {
            bool clockwise, start = true;
            for(int i = 0;i < points.size();i++)
            {
                int nextone = (i + 1 >= points.size() ? i + 1 - points.size() : i + 1);
                int nexttwo = (i + 2 >= points.size() ? i + 2 - points.size() : i + 2);
                vector<int> lineone({points[nextone][0] - points[i][0], points[nextone][1] - points[i][1]});
                vector<int> linetwo({points[nexttwo][0] - points[i][0], points[nexttwo][1] - points[i][1]});
                int res = crossProduct(lineone, linetwo);
                if(res != 0)
                {
                    if(start)
                    {
                        clockwise = res < 0;
                        start = false;
                    }
                    else
                    {
                        if(clockwise != (res < 0))
                            return false;
                    }
                }
                
            }
            return true;
        }
        
    }
    
    int crossProduct(const vector<int>& left, const vector<int>& right)
    {
        return left[0] * right[1] - right[0] * left[1];
    }
};



