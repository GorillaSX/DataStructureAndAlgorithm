/*
ou are given an integer array sorted in ascending order (may contain duplicates), you need to split them into several subsequences, where each subsequences consist of at least 3 consecutive integers. Return whether you can make such a split.

Example 1:
Input: [1,2,3,3,4,5]
Output: True
Explanation:
You can split them into two consecutive subsequences : 
1, 2, 3
3, 4, 5
Example 2:
Input: [1,2,3,3,4,4,5,5]
Output: True
Explanation:
You can split them into two consecutive subsequences : 
1, 2, 3, 4, 5
3, 4, 5
Example 3:
Input: [1,2,3,4,4,5]
Output: False
Note:
The length of the input is in range of [1, 10000]
*/
//The basic idea for solving this problem is, if an array could be split into several consecutive subsequences, each  sequence with at least three element, then when we iterate this array, for each num, there are must have a sequence that it should fit it, this sequence could appear earlyer, If there are multiply sequence that this num could fit in, we chose the shortest. If there are no sequence we can fit it, then this number must belong to later sequence, with at least three number. If at begining, when we need to start a new sequence, we using three number to generate this sequence, and tell what number we need next, thus, once , we could find a sequence to fit it, then we can do it. because we first guarantee each sequence has at least three numbers. 

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> maps;
        for(auto n : nums)
        {
            if(maps.count(n-1) == 0)
            {
                maps[n].push(1);
            }
            else
            {
                auto top = maps[n-1].top();
                maps[n-1].pop();
                if(maps[n-1].empty())
                    maps.erase(n-1);
                top++;
                maps[n].push(top);
            }
        }
        
        for(auto ele : maps)
        {
            while(ele.second.empty() == false)
            {
                if(ele.second.top() < 3)
                    return false;
                else
                    ele.second.pop();
            }
        }
        return true;
       
    }
};

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> remain, tails;
        for(auto n : nums)
        {
            remain[n]++;
            tails[n] = 0;
        }
        for(int i = 0;i < nums.size();i++)
        {
            if(remain[nums[i]] == 0) continue;
            else if(tails[nums[i] - 1] > 0)
            {
                tails[nums[i] - 1]--;
                tails[nums[i]]++;
            }
            else if(remain[nums[i] + 1] > 0 and remain[nums[i] + 2] > 0)
            {
                remain[nums[i]+1]--;
                remain[nums[i]+2]--;
                tails[nums[i] + 2]++;
            }
            else 
                return false;
            remain[nums[i]]--;
        }
        return true;
    }
};