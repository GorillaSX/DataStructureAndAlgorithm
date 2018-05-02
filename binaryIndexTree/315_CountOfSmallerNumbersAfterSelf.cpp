/*
You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].

Example:

Given nums = [5, 2, 6, 1]

To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.
Return the array [2, 1, 1, 0].
*/

class Solution {
public:
    void update(vector<int>& bit, int i, int val)
    {
        while(i < bit.size())
        {
            bit[i] += val;
            i += (i & - i);
        }
    }

    int sum(vector<int>& bit, int i)
    {
        int sum = 0;
        while(i > 0)
        {
            sum += bit[i];
            i -= (i & -i);
        }
        return sum;
    }
    vector<int> countSmaller(vector<int>& nums) {
       vector<int> results = vector<int>(nums.size(), 0);
       if(nums.size() == 0)
            return results;
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        unordered_map<int,int> hash;
        for(int i = 0;i < sorted.size();i++)
            hash[sorted[i]] = i + 1;
        vector<int> bit = vector<int>(sorted.size() + 1, 0);
        for(int i = nums.size() - 1;i >= 0; i--)
        {
            results[i] = sum(bit, hash[nums[i]] - 1);
            update(bit, hash[nums[i]], 1);
        }
        return results;
    }
};
