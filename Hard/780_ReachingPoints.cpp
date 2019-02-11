/*
780. Reaching Points
DescriptionHintsSubmissionsDiscussSolution
A move consists of taking a point (x, y) and transforming it to either (x, x+y) or (x+y, y).

Given a starting point (sx, sy) and a target point (tx, ty), return True if and only if a sequence of moves exists to transform the point (sx, sy) to (tx, ty). Otherwise, return False.

Examples:
Input: sx = 1, sy = 1, tx = 3, ty = 5
Output: True
Explanation:
One series of moves that transforms the starting point to the target is:
(1, 1) -> (1, 2)
(1, 2) -> (3, 2)
(3, 2) -> (3, 5)

Input: sx = 1, sy = 1, tx = 2, ty = 2
Output: False

Input: sx = 1, sy = 1, tx = 1, ty = 1
Output: True

Note:

sx, sy, tx, ty will all be integers in the range [1, 10^9].
*/
//The key point for this problem is sx, sy, ty, tx all > 0 this is very important, thus we can think about this question from destination to source. Because they all larger than zero. When we at destination (tx, ty), for previous position, could be (tx, tx + prey) or (prex + ty, ty) if ty > tx, because those position all larger then zero, there only one possible choice is (tx, tx + prey) if tx > ty, we only can choice (prex + ty, ty). we can do this all the time, but if( tx < sx) then return false 
class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while(sx < tx && sy < ty)
        {
            if(ty > tx) 
                ty %= tx;
            else        
                tx %= ty; 
        }
        if(sx == tx && (ty - sy) % sx == 0) return true;
        if(sy == ty && (tx - sx) % sy == 0) return true;
        return false;
    }
};