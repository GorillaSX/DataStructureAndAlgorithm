/*
658. Find K Closest Elements
DescriptionHintsSubmissionsDiscussSolution
Given a sorted array, two integers k and x, find the k closest elements to x in the array. The result should also be sorted in ascending order. If there is a tie, the smaller elements are always preferred.

Example 1:
Input: [1,2,3,4,5], k=4, x=3
Output: [1,2,3,4]
Example 2:
Input: [1,2,3,4,5], k=4, x=-1
Output: [1,2,3,4]
Note:
The value k is positive and will always be smaller than the length of the sorted array.
Length of the given array is positive and will not exceed 104
Absolute value of elements in the array and x will not exceed 104
*/
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        auto left = arr.begin(), right = arr.end() - 1;
        while(right - left + 1 > k)
        {
            if(x - *left > *right - x)
                left++;
            else 
                right--;
        }       
        return vector<int>(left, right + 1);
    }
};