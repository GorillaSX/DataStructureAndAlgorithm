/*
Given an integer array, return the k-th smallest distance among all the pairs. The distance of a pair (A, B) is defined as the absolute difference between A and B.

Example 1:
Input:
nums = [1,3,1]
k = 1
Output: 0 
Explanation:
Here are all the pairs:
(1,3) -> 2
(1,1) -> 0
(3,1) -> 2
Then the 1st smallest distance pair is (1,1), and its distance is 0.
Note:
2 <= len(nums) <= 10000.
0 <= nums[i] < 1000000.
1 <= k <= len(nums) * (len(nums) - 1) / 2.
*/
//Heap TLE
class comp 
{
    public:
    bool operator()(const pair<int, pair<int,int>>& lhs, const pair<int,pair<int,int>>& rhs) const
    {
        return lhs.first > rhs.first;
    }
};
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        typedef priority_queue<pair<int,pair<int,int>>, vector<pair<int, pair<int,int>>>, comp> pq;
        pq smallestPair;
        for(int i = 1;i < nums.size();i++)
        {
            smallestPair.push(make_pair(abs(nums[i] - nums[i-1]),make_pair(i-1, i)));
        }
        while(k > 0)
        {
            auto p = smallestPair.top();
            smallestPair.pop();
            k--;
            if(k == 0)
                return p.first;
            else 
            {
                while(p.second.first > 0 and nums[p.second.first-1] == nums[p.second.first])
                {
                    p.second.first--;
                    k--;
                    if(k == 0)
                        return p.first;
                }
                if(p.second.first > 0)
                {
                    smallestPair.push(make_pair(abs(nums[p.second.second] - nums[p.second.first - 1]), make_pair(p.second.first - 1, p.second.second)));
                }
            }
        }
    }
};

//Binary Search 
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int low = 0, high = nums.back() - nums.front();
        while(low < high)
        {
            int mid = (low + (high - low) / 2);
            int count = 0, start = 0, end = 1;
            for(end = 1; end < nums.size();end++)
            {
                while(start < end && nums[end] - nums[start] > mid)
                {
                    count += (end  - 1 - start);
                    start++;
                }
            }
            while(start < end)
            {
                count += (end - 1 - start);
                start++;
            }
            if(count >= k)
                high = mid;
            else if(count < k)
                low = mid + 1;
        }
        return low;
    }
};