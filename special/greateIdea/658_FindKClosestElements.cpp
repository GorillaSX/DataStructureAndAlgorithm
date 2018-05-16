/*
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
// Smartest solution 

//Because input is a sorted array, thus, the K closest elements should in contiguous, we can remove some elements to this K contiguous elements group, it's obvious that we should start from two side to chose elements to remove.
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        auto left = arr.begin(), right = arr.end() - 1; 
        while(right - left + 1 > k)
        {
            if(abs(*left - x) > abs(*right - x))
                left++;
            else 
                right--;
        }
        return vector<int>(left,  right + 1);
       
    }
};


class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> result;
        auto it = lower_bound(arr.begin(), arr.end(), x);
        if(it == arr.end())
            return vecto<int>(it - k, arr.end());
        else if(it == arr.begin())
            return vector<int>(it, it + k);
        auto left = it - 1, right = it;
        while(k > 0)
        {
            cout << *left << " " << *right << endl;
            if(left < arr.begin() && right != arr.end())
            {
                result.push_back(*right);
                right++;
            }
            else if(left != arr.begin() && right == arr.end())
            {
                result.push_back(*left);
                left--;
            }
            else 
            {
                if(abs(*left - x) <= abs(*right - x))
                {
                    result.push_back(*left);
                    left--;
                }
                else if(abs(*left - x) > abs(*right - x))
                {
                    result.push_back(*right);
                    right++;
                }
                
            }
            k--;
        }
        sort(result.begin(), result.end());
        return result;
       
    }
};

