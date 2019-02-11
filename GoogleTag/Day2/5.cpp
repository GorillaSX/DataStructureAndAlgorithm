/*
253. Meeting Rooms II
DescriptionHintsSubmissionsDiscussSolution
Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.

Example 1:

Input: [[0, 30],[5, 10],[15, 20]]
Output: 2
Example 2:

Input: [[7,10],[2,4]]
Output: 1
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
        int maxTimePoint = 0;
        for(auto interval : intervals)
            maxTimePoint = max(maxTimePoint, interval.end);
        vector<int> timeLine(maxTimePoint+1, 0);
        for(auto interval : intervals)
        {
            timeLine[interval.start] += 1;
            timeLine[interval.end] -= 1;
        }
        int count = 0, result = 0;
        for(int i = 0;i < timeLine.size();i++)
        {
            count += timeLine[i];
            result = max(result, count);
        }
        return result;
    }
};

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        map<int,int> timeLine;
        for(auto interval : intervals)
        {
            timeLine[interval.start] += 1;
            timeLine[interval.end ] -= 1;
        }       
        int result = 0;
        int count = 0;
        for(auto time : timeLine)
        {
            count += time.second;
            result = max(result, count);
        }
        return result;
    }
};