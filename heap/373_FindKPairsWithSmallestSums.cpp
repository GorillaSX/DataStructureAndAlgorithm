/*
You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.

Define a pair (u,v) which consists of one element from the first array and one element from the second array.

Find the k pairs (u1,v1),(u2,v2) ...(uk,vk) with the smallest sums.

Example 1:
Given nums1 = [1,7,11], nums2 = [2,4,6],  k = 3

Return: [1,2],[1,4],[1,6]

The first 3 pairs are returned from the sequence:
[1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
Example 2:
Given nums1 = [1,1,2], nums2 = [1,2,3],  k = 2

Return: [1,1],[1,1]

The first 2 pairs are returned from the sequence:
[1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
Example 3:
Given nums1 = [1,2], nums2 = [3],  k = 3 

Return: [1,3],[2,3]

All possible pairs are returned from the sequence:
[1,3],[2,3]
*/
class comp
{
    public:
    bool operator()(const pair<pair<int,int>, int>& lhs, const pair<pair<int,int>, int>& rhs)
    {
        return lhs.second > rhs.second;
    }
};
class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        typedef priority_queue<pair<pair<int,int>, int>, vector<pair<pair<int,int>, int>>, comp> pq;
        vector<pair<int,int>> results;
        if(nums1.size() == 0 || nums2.size() == 0)
            return results;
        pq mypq;
        mypq.push(make_pair(make_pair(0,0), nums1[0] + nums2[0]));
        int count = 0;
        set<pair<int,int>> visited;
        while(count != k && !mypq.empty())
        {
            auto tmp = mypq.top();
            mypq.pop();
            if(visited.find(tmp.first) == visited.end())
            {
                visited.insert(tmp.first);
            results.push_back(make_pair(nums1[tmp.first.first], nums2[tmp.first.second]));
            if(tmp.first.second + 1 < nums2.size())
                mypq.push(make_pair(make_pair(tmp.first.first, tmp.first.second + 1), nums1[tmp.first.first] + nums2[tmp.first.second + 1]));
            if(tmp.first.first + 1  < nums1.size())
                mypq.push(make_pair(make_pair(tmp.first.first + 1, tmp.first.second), nums1[tmp.first.first + 1] + nums2[tmp.first.second]));
            count++;
            }
        } 
        return results;
    }
};