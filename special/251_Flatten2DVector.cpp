/*

Implement an iterator to flatten a 2d vector.

Example:

Input: 2d vector =
[
  [1,2],
  [3],
  [4,5,6]
]
Output: [1,2,3,4,5,6]
Explanation: By calling next repeatedly until hasNext returns false, 
             the order of elements returned by next should be: [1,2,3,4,5,6].
Follow up:
As an added challenge, try to code it using only iterators in C++ or iterators in Java.
*/

class Vector2D {
public:
    vector<vector<int>>::iterator start2d, end2d;
    vector<int>::iterator  start1d, end1d;
    
    Vector2D(vector<vector<int>>& vec2d) {
        start2d = vec2d.begin();
        end2d = vec2d.end();
        if(start2d != end2d)
        {
            start1d = start2d->begin();
            end1d = start2d->end();
        }
    }

    int next() {
        return *start1d++;
        
    }

    bool hasNext() {
        while(start2d != end2d and start1d == end1d)
        {
            start2d++;
            if(start2d == end2d)
                return false;
            start1d = start2d->begin();
            end1d = start2d->end();
        }
        if(start2d == end2d)
            return false;
        return true;
        
    }
};
