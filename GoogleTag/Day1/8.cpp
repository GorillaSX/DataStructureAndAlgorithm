/*
583. Delete Operation for Two Strings
DescriptionHintsSubmissionsDiscussSolution
Given two words word1 and word2, find the minimum number of steps required to make word1 and word2 the same, where in each step you can delete one character in either string.

Example 1:
Input: "sea", "eat"
Output: 2
Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".
Note:
The length of given words won't exceed 500.
Characters in given words can only be lower-case letters.
*/
class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> memory(word1.size()+1, vector<int>(word2.size() + 1, 0));
        for(int i = 1;i <= word1.size();i++)
        {
            for(int j = 1;j <= word2.size();j++)
            {
                if(word1[i-1] == word2[j-1])
                {
                    memory[i][j] = 1 + memory[i-1][j-1];
                }
                memory[i][j] = max(memory[i][j], max(memory[i][j-1], memory[i-1][j]));
            }
        }
        return word1.size() + word2.size() - 2 * memory[word1.size()][word2.size()];
    }
};