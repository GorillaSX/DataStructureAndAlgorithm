/*854. K-Similar Strings
DescriptionHintsSubmissionsDiscussSolution
Strings A and B are K-similar (for some non-negative integer K) if we can swap the positions of two letters in A exactly K times so that the resulting string equals B.

Given two anagrams A and B, return the smallest K for which A and B are K-similar.

Example 1:

Input: A = "ab", B = "ba"
Output: 1
Example 2:

Input: A = "abc", B = "bca"
Output: 2
Example 3:

Input: A = "abac", B = "baca"
Output: 2
Example 4:

Input: A = "aabc", B = "abca"
Output: 2
Note:

1 <= A.length == B.length <= 20
A and B contain only lowercase letters from the set {'a', 'b', 'c', 'd', 'e', 'f'}
*/
class Solution {
public:
    int kSimilarity(string A, string B) {
         unordered_set<string> visited;  
         queue<string> BFS;
         int step = 0;
         BFS.push(A);
         visited.insert(A);
         while(!BFS.empty())
         {
             int size = BFS.size();
             for(int i = 0;i < size;i++)
             {
                string source = BFS.front(); BFS.pop();
                int index = 0;
                for(index = 0; index < source.size();index++)
                {
                    if(source[index] != B[index])
                        break;
                }              
                if(index == source.size())
                    return step;
                else 
                {
                    vector<int> targetPos;
                    for(int j = 0;j < source.size();j++)
                    {
                        if(source[j] == B[index])
                            targetPos.push_back(j);
                    }
                    for(auto pos : targetPos)
                    {
                       string tmp = source;
                       tmp[index] = B[index];
                       tmp[pos] = source[index];  
                       if(visited.count(tmp) == 0)
                       {
                           visited.insert(tmp);
                           BFS.push(tmp);
                       } 
                    }
                } 
             }
             step++;
         }
    }
};