/*
659. Split Array into Consecutive Subsequences
DescriptionHintsSubmissionsDiscussSolution
You are given an integer array sorted in ascending order (may contain duplicates), you need to split them into several subsequences, where each subsequences consist of at least 3 consecutive integers. Return whether you can make such a split.

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
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int> needed;
        unordered_map<int,int> unused;
        for(auto n : nums)
            unused[n]++;
        for(auto n : nums)
        {
            if(unused.count(n) == 0)  continue;
            else if(needed.count(n) != 0)
            {
                if(--needed[n] == 0)
                    needed.erase(n);
                needed[n+1]++;
            }
            else if(unused.count(n+1) != 0 && unused.count(n+2) != 0)
            {
                if(--unused[n+1] == 0)
                    unused.erase(n+1);
                if(--unused[n+2] == 0)
                    unused.erase(n+2);
                needed[n+3]++;
            }
            else 
                return false;
            if(--unused[n] == 0)
                unused.erase(n);
        }
        return true;
    }
};