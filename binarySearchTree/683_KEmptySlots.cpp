/*
There is a garden with N slots. In each slot, there is a flower. The N flowers will bloom one by one in N days. In each day, there will be exactly one flower blooming and it will be in the status of blooming since then.

Given an array flowers consists of number from 1 to N. Each number in the array represents the place where the flower will open in that day.

For example, flowers[i] = x means that the unique flower that blooms at day i will be at position x, where i and x will be in the range from 1 to N.

Also given an integer k, you need to output in which day there exists two flowers in the status of blooming, and also the number of flowers between them is k and these flowers are not blooming.

If there isn't such day, output -1.

Example 1:
Input: 
flowers: [1,3,2]
k: 1
Output: 2
Explanation: In the second day, the first and the third flower have become blooming.
Example 2:
Input: 
flowers: [1,2,3]
k: 1
Output: -1
*/
class Solution {
public:
    int kEmptySlots(vector<int>& flowers, int k) {
        if(flowers.size() < k + 2)
            return -1;
        int n = flowers.size();
        vector<int> days(n + 1, 0);
        for(int i = 0;i < flowers.size();i++)
        {
            days[flowers[i]] = i + 1;
        } 
        set<int> slots;
        int results = n+1;
        for(int i = 1;i < days.size();i++)
        {
            slots.insert(days[i]);
            if(i > k + 1)
            {
                slots.erase(days[i - k - 2]);
            }
            if(i >= k + 1)
            {
                int left = days[i - k - 1];
                int right = days[i];
                auto it = slots.begin();
                int first  = *it;
                int second = *(++it);
                if(left < right && left == first && right == second)
                    results = min(right, results);
                else if(left > right && right == first && left == second)
                    results = min(left, results);;
            }
        }
        return results == n + 1 ? - 1 : results;
    }
};

//Solution two
class Solution {
public:
    int kEmptySlots(vector<int>& flowers, int k) {
        if(flowers.size() < k + 2)
            return -1;
        set<int> slots;
        int n = flowers.size();
        slots.insert(flowers[0]);
        for(int i = 1;i < flowers.size();i++)
        {
           int curSlot = flowers[i];
           slots.insert(curSlot);
           auto it = slots.find(curSlot); 
           if(curSlot +k + 1 <= n)
           {
               if((++it) != slots.end() && curSlot + k + 1 == *it)
                    return i + 1;
           }
           if(curSlot -k - 1 >= 0)
           {
               it = slots.find(curSlot);
               if(it != slots.begin() &&  (curSlot - k - 1) == *(--it))
                    return i + 1;
           }
        }
        return -1;
    }
};