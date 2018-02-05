/*
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
*/
 bool myfunction(Interval left, Interval right)
    {
        return left.start < right.start;
    }
class Solution {
public:
   
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), myfunction);
        vector<Interval> results;
        if(intervals.size() == 0)
            return results;
        Interval interval = Interval(intervals[0].start, intervals[0].end); 
        for(int i = 1;i < intervals.size();i++)
        {
            if(intervals[i].start > interval.end)
            {
                results.push_back(interval); 
                interval = Interval(intervals[i].start, intervals[i].end);
            }
            else if(intervals[i].start <= interval.end)
            {
                interval.end = interval.end <= intervals[i].end ? intervals[i].end : interval.end;
            }
        }
        results.push_back(interval);
        return results;
    }
};