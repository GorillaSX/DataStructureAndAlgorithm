/*
Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.

For example,
[2,3,4] , the median is 3 

[2,3], the median is (2 + 3) / 2 = 2.5 

Design a data structure that supports the following two operations:

void addNum(int num) - Add a integer number from the data stream to the data structure.
double findMedian() - Return the median of all elements so far.
Example:

addNum(1)
addNum(2)
findMedian() -> 1.5
addNum(3) 
findMedian() -> 2
*/
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
       if(minHeap.size() != 0 && num > minHeap.top())
            maxHeap.push(num);
       else 
            minHeap.push(num);
       if(maxHeap.size() > minHeap.size())
       {
           minHeap.push(maxHeap.top());
           maxHeap.pop();
       }    
       else if(minHeap.size() - maxHeap.size() > 1)
       {
           maxHeap.push(minHeap.top());
           minHeap.pop(); 
       }
    }
    
    double findMedian() {
        if(maxHeap.size() == minHeap.size())
        {
           return (double(minHeap.top()) + double(maxHeap.top())) / 2.0;
        }
        else 
            return minHeap.top();
        
    }
    priority_queue<int, vector<int>, greater<int>> maxHeap;
    priority_queue<int, vector<int>> minHeap;
};
