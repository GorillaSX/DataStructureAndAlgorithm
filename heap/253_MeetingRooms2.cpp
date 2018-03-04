/*
Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.

For example,
Given [[0, 30],[5, 10],[15, 20]],
return 2.
*/
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        map<int, int> s;
        for(auto interval: intervals)
        {
            s[interval.start]++;
            s[interval.end]--;
        }       
        int maxRoom = 0;
        int count = 0;
        for(auto ele : s)
        {
            count += ele.second;
            maxRoom = max(maxRoom, count);

        }
        return maxRoom;        
    }
};