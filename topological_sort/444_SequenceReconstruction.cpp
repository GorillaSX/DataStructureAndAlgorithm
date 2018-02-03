/*
Check whether the original sequence org can be uniquely reconstructed from the sequences in seqs. The org sequence is a permutation of the integers from 1 to n, with 1 ≤ n ≤ 104. Reconstruction means building a shortest common supersequence of the sequences in seqs (i.e., a shortest sequence so that all sequences in seqs are subsequences of it). Determine whether there is only one sequence that can be reconstructed from seqs and it is the org sequence.

Example 1:

Input:
org: [1,2,3], seqs: [[1,2],[1,3]]

Output:
false

Explanation:
[1,2,3] is not the only one sequence that can be reconstructed, because [1,3,2] is also a valid sequence that can be reconstructed.
Example 2:

Input:
org: [1,2,3], seqs: [[1,2]]

Output:
false

Explanation:
The reconstructed sequence can only be [1,2].
Example 3:

Input:
org: [1,2,3], seqs: [[1,2],[1,3],[2,3]]

Output:
true

Explanation:
The sequences [1,2], [1,3], and [2,3] can uniquely reconstruct the original sequence [1,2,3].
Example 4:

Input:
org: [4,1,5,2,6,3], seqs: [[5,2,6,3],[4,1,5,2]]

Output:
true
*/

//Solution

class Solution 
{
    public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs)
    {
        unordered_map<int, pair<vector<int>, int>> adjTable;
        for(auto& seq : seqs)
        {
            for(int i = 0;i < seq.size();i++)
            {
                if(i == seq.size() - 1)
                {
                    if(adjTable.count(seq[i]) == 0)
                        adjTable[seq[i]].second = 0;
                    continue;
                }
                int in = seq[i];
                int out = seq[i+1];
                if(adjTable.count(in) == 0)
                    adjTable[in].second = 0;
                adjTable[in].first.push_back(out);
                if(adjTable.count(out) == 0)
                    adjTable[out].second = 1;
                else
                    adjTable[out].second++;
            }
        }
        queue<int> start;
        vector<int> res;
        if(adjTable.size() == 0)
            return org.size() == 0 ? true : false;
        for(auto& ele : adjTable)
        {
            if(ele.second.second == 0)
                start.push(ele.first);
        }
        while(start.size() != 0 )
        {
            if(start.size() != 1)
                return false;
            int in = start.front();
            res.push_back(in);
            start.pop();
            for(auto& out : adjTable[in].first)
            {
                adjTable[out].second--;
                if(adjTable[out].second == 0)
                    start.push(out);
            }
            adjTable.erase(in);
        }
        if(adjTable.size() != 0 || res.size() != org.size())
            return false;
        for(int i = 0;i < res.size() ;i++)
        {
            if(res[i] != org[i])
                return false;
        }
        return true;
    }
};  