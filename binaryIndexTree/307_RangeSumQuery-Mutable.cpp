/*
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

The update(i, val) function modifies nums by updating the element at index i to val.
Example:
Given nums = [1, 3, 5]

sumRange(0, 2) -> 9
update(1, 2)
sumRange(0, 2) -> 8
Note:
The array is only modifiable by the update function.
You may assume the number of calls to update and sumRange function is distributed evenly.
*/
class NumArray {
public:
    vector<int> m_sums;
    vector<int> m_nums;
    NumArray(vector<int> nums) {
       m_sums = vector<int>(nums.size() + 1, 0);
       m_nums = vector<int>(nums.size(), 0);
       for(int i = 0;i < m_nums.size();i++)
       {
           update(i, nums[i]);
       }
    }
    
    void update(int i, int val) 
    {
        int updateVal = val - m_nums[i];
        m_nums[i] = val;
        ++i;
        while(i < m_sums.size())
        {
            m_sums[i] += updateVal;
            i += (i & -i);
        }
    }

    int sum(int i)
    {
        int sums = 0;
        ++i;
        while(i > 0)
        {
            sums += m_sums[i];
            i -= (i & -i);
        }
        return sums;
    }
    
    int sumRange(int i, int j) {
       return sum(j) - sum(i-1); 
    }
};