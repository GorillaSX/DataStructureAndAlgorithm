/*
Given N axis-aligned rectangles where N > 0, determine if they all together form an exact cover of a rectangular region.

Each rectangle is represented as a bottom-left point and a top-right point. For example, a unit square is represented as [1,1,2,2]. (coordinate of bottom-left point is (1, 1) and top-right point is (2, 2)).


Example 1:

rectangles = [
  [1,1,3,3],
  [3,1,4,2],
  [3,2,4,4],
  [1,3,2,4],
  [2,3,3,4]
]

Return true. All 5 rectangles together form an exact cover of a rectangular region.

Example 2:

rectangles = [
  [1,1,2,3],
  [1,3,2,4],
  [3,1,4,2],
  [3,2,4,4]
]

Return false. Because there is a gap between the two rectangular regions.

Example 3:

rectangles = [
  [1,1,3,3],
  [3,1,4,2],
  [1,3,2,4],
  [3,2,4,4]
]

Return false. Because there is a gap in the top center.

Example 4:

rectangles = [
  [1,1,3,3],
  [3,1,4,2],
  [1,3,2,4],
  [2,2,4,4]
]

Return false. Because two of the rectangles overlap with each other.
*/
class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int l = INT_MAX, r = INT_MIN, t = INT_MIN, b = INT_MAX;
        int area = 0;
        //unordered_set<string> cornersets;
        unordered_set<long long> cornersets;
        for(auto rec : rectangles)
        {
           area += ((rec[2] - rec[0]) * (rec[3] - rec[1])); 
           l = min(l, rec[0]);
           r = max(r, rec[2]);
           b = min(b, rec[1]);
           t = max(t, rec[3]);  
           /*string lb = connect(rec[0], rec[1]);
           string lt = connect(rec[0], rec[3]);
           string rb = connect(rec[2], rec[1]); 
           string rt = connect(rec[2], rec[3]); */
           long long lb = connect(rec[0], rec[1]);
           long long lt = connect(rec[0], rec[3]);
           long long rb = connect(rec[2], rec[1]); 
           long long rt = connect(rec[2], rec[3]); 
           if(cornersets.count(lb) == 0)
                cornersets.insert(lb);
           else  
               cornersets.erase(lb);
            
           if(cornersets.count(lt) == 0)
                cornersets.insert(lt);
           else  
               cornersets.erase(lt);
            
           if(cornersets.count(rb) == 0)
                cornersets.insert(rb);
           else  
               cornersets.erase(rb);
            
           if(cornersets.count(rt) == 0)
                cornersets.insert(rt);
           else  
               cornersets.erase(rt);
            
        }
        
        if(cornersets.count(connect(l, b)) == 0 || cornersets.count(connect(l, t)) == 0 || cornersets.count(connect(r,b)) == 0 || cornersets.count(connect(r,t)) == 0|| cornersets.size() != 4)
            return false;
        return area == ((r - l) * (t - b));
        
    }
    long long connect(uint left, uint right)
    {
        long long res = 0;
        long long l = (res | left) << 32;
        long long r = (res | right);
        res = l| r;
        return res; 
        //string res =  to_string(left) + " " + to_string(right);
        //return res;
    }
};