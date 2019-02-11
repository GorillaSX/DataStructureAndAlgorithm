/*
251. Flatten 2D Vector
DescriptionHintsSubmissionsDiscussSolution
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

    Vector2D(vector<vector<int>>& vec2d) {
       outBegin = vec2d.begin();
       outEnd = vec2d.end();
       if(outBegin != outEnd) 
       {
            inBegin = outBegin->begin();
            inEnd = outBegin->end(); 
       }
    }

    int next() {
       int val = *(inBegin++);
       return val;
    }

    bool hasNext() {
        if(outBegin == outEnd)
            return false;
        while(inBegin == inEnd)
        {
            outBegin++;
            if(outBegin == outEnd)
                return false;

             inBegin = outBegin->begin();
             inEnd = outBegin->end();
        }        
        return true;
    }
private:
    vector<vector<int>>::iterator outBegin, outEnd;
    vector<int>::iterator inBegin, inEnd;
};