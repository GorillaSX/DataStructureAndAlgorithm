/*
Design a hit counter which counts the number of hits received in the past 5 minutes.

Each function accepts a timestamp parameter (in seconds granularity) and you may assume that calls are being made to the system in chronological order (ie, the timestamp is monotonically increasing). You may assume that the earliest timestamp starts at 1.

It is possible that several hits arrive roughly at the same time.

Example:
HitCounter counter = new HitCounter();

// hit at timestamp 1.
counter.hit(1);

// hit at timestamp 2.
counter.hit(2);

// hit at timestamp 3.
counter.hit(3);

// get hits at timestamp 4, should return 3.
counter.getHits(4);

// hit at timestamp 300.
counter.hit(300);

// get hits at timestamp 300, should return 4.
counter.getHits(300);

// get hits at timestamp 301, should return 3.
counter.getHits(301); 
Follow up:
What if the number of hits per second could be very large? Does your design scale?
*/
class HitCounter {
public:
    /** Initialize your data structure here. */
    HitCounter() {
        
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        hits.push(timestamp);
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        int target = timestamp - 300 + 1;
        while(hits.size() != 0 and hits.front() < target)
            hits.pop();
        return hits.size();
    }
private:
    queue<int> hits;
};
//Th above solution is not scalable when the number of hit per second very large. Then there is a more scalable solution. 
class HitCounter {
public:
    /** Initialize your data structure here. */
    HitCounter() {
        
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        int index = timestamp % 300; 
        if(times[index ] != timestamp)
        {
            times[index] = timestamp;
            hits[index] = 1;
        }    
        else 
            hits[index]++;
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        int count = 0;
        for(int i = 0;i < 300;i++)
        {
            if(times[i] >= (timestamp - 300 + 1))
                count += hits[i];
        }
        return count; 
    }
private:
    vector<int> times(300, 0);
    vector<int> hits(300, 0);
};

