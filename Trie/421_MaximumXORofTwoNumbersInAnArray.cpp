/*
Given a non-empty array of numbers, a0, a1, a2, … , an-1, where 0 ≤ ai < 231.

Find the maximum result of ai XOR aj, where 0 ≤ i, j < n.

Could you do this in O(n) runtime?

Example:

Input: [3, 10, 5, 25, 2, 8]

Output: 28

Explanation: The maximum result is 5 ^ 25 = 28.
*/
struct Trie 
{
    Trie* member[2] = {NULL, NULL};
    Trie(){}
    void insert(int number)
    {
        Trie* node = this;
        for(int i = 31;i >= 0;i--)
        {
            int index = (number >> i ) & 1;
            if(node->member[index] == NULL)
            {
                node->member[index] = new Trie();
            }
            node = node->member[index];
        }
    }
    int query(int number)
    {
        Trie* node = this;
        int results = 0;
        for(int i = 31;i >=0; i--)
        {
            int index = ((number >> i) & 1) == 1 ? 0 : 1 ;
            if(node->member[index] != NULL)
            {
                results += (1 << i);
                node = node->member[index];
            }
            else 
            {
                node = node->member[1 - index];
            }
        }
        return results;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
       Trie* root = new Trie();
       int res = 0;
       for(auto n : nums)
       {
           root->insert(n);
       } 
       for(auto n : nums)
       {
           res = max(res, root->query(n));
       }
       return res; 
    }
};