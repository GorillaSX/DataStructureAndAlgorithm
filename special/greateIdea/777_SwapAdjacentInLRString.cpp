/*

In a string composed of 'L', 'R', and 'X' characters, like "RXXLRXRXL", a move consists of either replacing one occurrence of "XL" with "LX", or replacing one occurrence of "RX" with "XR". Given the starting string start and the ending string end, return True if and only if there exists a sequence of moves to transform one string to the other.

Example:

Input: start = "RXXLRXRXL", end = "XRLXXRRLX"
Output: True
Explanation:
We can transform start to end following these steps:
RXXLRXRXL ->
XRXLRXRXL ->
XRLXRXRXL ->
XRLXXRRXL ->
XRLXXRRLX
Note:

1 <= len(start) = len(end) <= 10000.
Both start and end will only consist of characters in {'L', 'R', 'X'}.
*/


class Solution {
public:
    bool canTransform(string start, string end) {
        int si = 0, ei = 0;
        do
        {
            while(si < start.size() && start[si] == 'X')
                si++;
            while(ei < end.size() && end[ei] == 'X')
                ei++;
            if(si == start.size() && ei == end.size())
                return true;
            else if((si == start.size() && ei != end.size()) or (si != start.size() && ei == start.size()))
                return false;
            else
            {
                if(start[si] != end[ei] or (start[si] == 'L' and si < ei) or (start[si] == 'R' and si > ei))
                   return false;
                si++;
                ei++;
            }
        }while(true);
        return true;
        
    }
};