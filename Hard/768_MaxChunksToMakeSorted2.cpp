/*
This question is the same as "Max Chunks to Make Sorted" except the integers of the given array are not necessarily distinct, the input array could be up to length 2000, and the elements could be up to 10**8.

Given an array arr of integers (not necessarily distinct), we split the array into some number of "chunks" (partitions), and individually sort each chunk.  After concatenating them, the result equals the sorted array.

What is the most number of chunks we could have made?

Example 1:

Input: arr = [5,4,3,2,1]
Output: 1
Explanation:
Splitting into two or more chunks will not return the required result.
For example, splitting into [5, 4], [3, 2, 1] will result in [4, 5, 1, 2, 3], which isn't sorted.
Example 2:

Input: arr = [2,1,3,4,4]
Output: 4
Explanation:
We can split into two chunks, such as [2, 1], [3, 4, 4].
However, splitting into [2, 1], [3], [4], [4] is the highest number of chunks possible.
*/
//O(nlogn)
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int> tmp = arr;
        sort(tmp.begin(), tmp.end());
        unordered_map<int, int> indexMap;
        for(int i = 0;i < tmp.size();i++)
        {
            if(indexMap.count(tmp[i]) == 0)
            {
                indexMap[tmp[i]] = i;
            }
        }
        vector<int> index(arr.size(), 0);
        for(int i = 0;i < arr.size();i++)
        {
            index[i] = indexMap[arr[i]];
            indexMap[arr[i]]++;
        }
        int res = 0, target = 0;
        for(int i = 0;i < index.size();i++)
        {
           target = max(target, index[i]);
           if(i == target)
                res++;
        }
        return res; 

    }
};

//O(n)
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int> smallAfter(arr.size(), 0);
        smallAfter[arr.size()-1] = arr.back();
        for(int i = arr.size() - 2;i >= 0;i--)
            smallAfter[i] = min(arr[i+1], smallAfter[i+1]);
        int res = 0, m = INT_MIN;
        for(int i = 0;i < smallAfter.size();i++)
        {
            m =  max(m, arr[i]);
            if(i == arr.size() - 1 || m <= smallAfter[i])
                res++;
        }
        return res; 
    }
};