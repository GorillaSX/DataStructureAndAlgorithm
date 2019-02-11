/*
835. Image Overlap
DescriptionHintsSubmissionsDiscussSolution
Two images A and B are given, represented as binary, square matrices of the same size.  (A binary matrix has only 0s and 1s as values.)

We translate one image however we choose (sliding it left, right, up, or down any number of units), and place it on top of the other image.  After, the overlap of this translation is the number of positions that have a 1 in both images.

(Note also that a translation does not include any kind of rotation.)

What is the largest possible overlap?

Example 1:

Input: A = [[1,1,0],
            [0,1,0],
            [0,1,0]]
       B = [[0,0,0],
            [0,1,1],
            [0,0,1]]
Output: 3
Explanation: We slide A to right by 1 unit and down by 1 unit.
*/
class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int m = A.size();
        int n = m ? A[0].size() : 0;
        unordered_map<string, int> offset;
        for(int i = 0;i < m;i++)
        {
            for(int j = 0;j < n;j++)
            {
                if(A[i][j] == 1)
                {
                    for(int p = 0;p < m;p++)
                    {
                        for(int q = 0; q < n;q++)
                        {
                            if(B[p][q] == 1)
                            {
                                string off = to_string(p-i) + "," + to_string(q - j);
                                offset[off]++;
                            }
                        }
                    }
                }
            }
        }       
            int count= 0;
            for(auto ele : offset)
            {
                count = max(count, ele.second);
            }
            return count;
    }
};