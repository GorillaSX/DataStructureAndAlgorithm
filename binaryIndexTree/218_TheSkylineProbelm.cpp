/*
A city's skyline is the outer contour of the silhouette formed by all the buildings in that city when viewed from a distance. Now suppose you are given the locations and height of all the buildings as shown on a cityscape photo (Figure A), write a program to output the skyline formed by these buildings collectively (Figure B).

 Buildings  Skyline Contour
The geometric information of each building is represented by a triplet of integers [Li, Ri, Hi], where Li and Ri are the x coordinates of the left and right edge of the ith building, respectively, and Hi is its height. It is guaranteed that 0 ≤ Li, Ri ≤ INT_MAX, 0 < Hi ≤ INT_MAX, and Ri - Li > 0. You may assume all buildings are perfect rectangles grounded on an absolutely flat surface at height 0.

For instance, the dimensions of all buildings in Figure A are recorded as: [ [2 9 10], [3 7 15], [5 12 12], [15 20 10], [19 24 8] ] .

The output is a list of "key points" (red dots in Figure B) in the format of [ [x1,y1], [x2, y2], [x3, y3], ... ] that uniquely defines a skyline. A key point is the left endpoint of a horizontal line segment. Note that the last key point, where the rightmost building ends, is merely used to mark the termination of the skyline, and always has zero height. Also, the ground in between any two adjacent buildings should be considered part of the skyline contour.

For instance, the skyline in Figure B should be represented as:[ [2 10], [3 15], [7 12], [12 0], [15 10], [20 8], [24, 0] ].

Notes:

The number of buildings in any input list is guaranteed to be in the range [0, 10000].
The input list is already sorted in ascending order by the left x position Li.
The output list must be sorted by the x position.
There must be no consecutive horizontal lines of equal height in the output skyline. For instance, [...[2 3], [4 5], [7 5], [11 5], [12 7]...] is not acceptable; the three lines of height 5 should be merged into one in the final output as such: [...[2 3], [4 5], [12 7], ...]
*/
//Binary Index tree solution

class Solution {
public:
    void update(vector<int>& bit, int index, int val)
    {
         while(index > 0)
         {
             bit[index] = max(bit[index], val);
             index -= (index & -index);
         } 
    }
    int find(vector<int>& bit, int index)
    {
        int res = 0;
        while(index < bit.size())
        {
            res = max(res, bit[index]);
            index += (index & -index);
        }
        return res;
    }
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int,int>> res;
        if(buildings.size() == 0)
            return res;
        vector<vector<int>> points;
        for(int i = 0;i < buildings.size();i++)
        {
            points.push_back(vector<int>{buildings[i][0], 1, i});
            points.push_back(vector<int>{buildings[i][1], 2, i});
        }
        sort(points.begin(), points.end());
        unordered_map<int, int> hash;
        int index = 1;
        for(int i = 0;i < points.size();i++)
        {
            if(hash.count(points[i][0]) == 0)
            {
                hash[points[i][0]] = index;
                index++;
            }
        }
        vector<int> bit = vector<int>(index, 0);
        int curH = 0;
        for(auto point : points)
        {
            int L = 0;
            if(point[1] == 1)
            {
                L = buildings[point[2]][0];
                int R = buildings[point[2]][1];
                int V = buildings[point[2]][2];
                update(bit, hash[R] -1 , V);
            }
            else
                L = point[0];
            int height = find(bit, hash[L]); 
            if(height != curH)
            {
                if(res.size() != 0 && (res.back()).first == L)
                    (res.back()).second = max((res.back()).second, height);
                else
                    res.push_back(make_pair(L, height));
                curH = height;
            }
        }
        return res;
    }
};