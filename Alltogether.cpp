#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <list>
#include <limits>

using namespace std;
/*--------------Sort And Search Section----------------------*/

void bubbleSort(vector<int>& unsortedArray)
{
    int arraySize = unsortedArray.size();
    for(int i = 0;i < arraySize - 1;i++)
    {
        for(int j = 0;j < arraySize - i - 1; j++)
        {
            if(unsortedArray[j] > unsortedArray[j+1])
                swap(unsortedArray[j], unsortedArray[j+1]);
        }
    }
}

void SelectionSort(vector<int>& unsortedArray)
{
    int arraySize = unsortedArray.size();
    for(int i = 0;i < arraySize - 1;i++)
    {
        int minIndex = i;
        for(int j = i; j < arraySize; j++)
        {
            if(unsortedArray[j] < unsortedArray[minIndex])
                minIndex = j;
        }
        swap(unsortedArray[i], unsortedArray[minIndex]);
    }
}

//Insertion Sort
void insertionSort(vector<int>& unsortedArray)
{
    int arraySize = unsortedArray.size();
    for(int i = 1;i < arraySize; i++)
    {
        int key = unsortedArray[i];
        int j = i;
        while( j - 1 >= 0 and unsortedArray[j-1] > key)
        {
            unsortedArray[j] = unsortedArray[j-1];
            j--;
        }
        unsortedArray[j] = key;
    }
}
//Merge sort
/*
Time complexity: O(nlogn)
Space Complexity: O(n)
Algorithm Paradigm: Divide and Conquer
Stable: Yes
Application:
1. Merge Sort is useful for sorting linked list in O(nlong) time. Because we cannot random access elements in linked list, thus quick sort is bad in Linked list sort
2. Inversion Count problem 
*/
void merge(vector<int>& array, vector<int>& helper, int left, int mid, int end)
{
    for(int i = left; i <= end;i++)
        helper[i] = array[i];
    int helperleft = left;
    int helperright = mid + 1;
    int current = left;

    while(helperleft <= mid and helperright <= end)
    {
        if(helper[helperright] < helper[helperleft])
        {
            array[current] = helper[helperright];
            helperright++;
        }
        else
        {
            array[current] = helper[helperleft];
            helperleft++;
        } 
        current++;
    }
    while(helperright > end and helperleft <= mid)
    {
        array[current] = helper[helperleft];
        helperleft++;
        current++;
    }
}
void mergeSort(vector<int>& unsortedArray, vector<int>& helper, int begin, int end)
{
    if(begin < end)
    {
        int mid = (begin + end) / 2;
        mergeSort(unsortedArray, helper, begin, mid);
        mergeSort(unsortedArray, helper, mid+1, end);
        merge(unsortedArray, helper, begin, mid, end);
    }
}
void mergeSort(vector<int>& unsortedArray)
{
    vector<int> helper(unsortedArray.size(), 0);
    mergeSort(unsortedArray, helper, 0, unsortedArray.size() - 1);   
}

//QuickSort
/*
Quick Sort is a Divide and Conquer algorithm. It picks an element as pivot and partitions the given array around the picked pivot.  There are many different versions of quickSort that pick pivot in different ways. 
1. Always pick first element as pivot
2. Always pick last element as pivot
3. pick a random element as pivot
4. pick median as pivot

Time complexity: best:O(nlogn), Average: O(nlogn), worst: O(n*n)
3-way quickSort:
1. arr[l..i] elements less than pivot
2. arr[i+1..j-1] elements equal to pivot
3. arr[j..r] elements greater than pivot
QuickSort Iteratively
*/
//chose mid element as pivot quicksort
int partitionMid(vector<int>& unsortedArray, int begin, int end)
{
    if(begin < end)
    {
        int mid = (begin + end) / 2;
        int pivot = unsortedArray[mid];

        int l = begin, r = end;
        while(l <= r)
        {
           while(unsortedArray[l] < pivot)
                l++;
           while(unsortedArray[r] > pivot)
                r--;
           if(l <= r)
           {
               swap(unsortedArray[l], unsortedArray[r]);
               l++;
               r--;
           }
        }
        return l;
    }
    return begin;
}

//Using late element as pivot
int partitionLast(vector<int>& unsortedArray, int begin, int end)
{
    if(begin < end)
    {
        int pivot = unsortedArray[end];
        int current = begin;
        for(int i = begin; i <= end; i++ )
        {
            if(unsortedArray[i] <= pivot)
            {
                swap(unsortedArray[current], unsortedArray[i]);
                current++;
            }
        }
        return current - 1;
    }
    return begin;
}
void quickSort(vector<int>& unsortedArray, int begin, int end)
{
    int index = partitionLast(unsortedArray, begin, end);
    if(begin < index - 1)
        quickSort(unsortedArray, begin, index - 1);
    if(index < end)
        quickSort(unsortedArray, index, end);
}
//Quick Select 
/*
Time Complexity: Worst: O(n*n), Best: O(n), Average: O(n)
*/
void nth_element(vector<int>& unsortedArray, int begin, int index, int end)
{
    int i = partitionLast(unsortedArray, begin, end);
    int l = begin, r = end;
    while(i != index)
    {
        if(index > i)
            l = i + 1;
        else 
            r = i - 1;
        i = partitionLast(unsortedArray, l, r);
    }
}

//Binary Search

int BinarySearch(vector<int>& sortedArray, int val)
{
    int left = 0, right = sortedArray.size() - 1;
    while(left <= right)
    {
        int mid = (left + right) / 2;
        if(sortedArray[mid] == val)
            return mid;
        else if(val > sortedArray[mid])
            left = mid + 1;
        else 
            right = mid - 1;
    }
    return -1;
}
/*---------------End of Sort and Search---------------------*/

/*--------------Start of Divide-And-Conquer-----------------*/
/*
In computer science, DivideAndConquer is an algorithm design paradigm based on multi-branched recursion. A divide and conquer algorithm works by recursively breaking down a problem into two or more sub-problem of the same or related type, until these become simple enough to be solved directly. The solution to the sub-problems are then combined to give a solution to the original problem.

Understanding and designing divide and conquer algorithms is a complex skill that requires a good understanding of the nature of the underlying problem to be solved. 
*/
/* There are two examples:
1. LeetCode 282. ExpressionAndOperators
Given a string that contains only digits 0-9 and a target value, return all possibilities to add binary operators (not unary) +, -, or * between the digits so they evaluate to the target value.

Example 1:

Input: num = "123", target = 6
Output: ["1+2+3", "1*2*3"] 
Example 2:

Input: num = "232", target = 8
Output: ["2*3+2", "2+3*2"]
Example 3:

Input: num = "105", target = 5
Output: ["1*0+5","10-5"]
Example 4:

Input: num = "00", target = 0
Output: ["0+0", "0-0", "0*0"]
Example 5:

Input: num = "3456237490", target = 9191
Output: []
*/

Solution:
class Solution {
public:
    void dfs(string num, int target, vector<string>& result, string prevString, int startPos, long long cumulativeValue, long long preValue, char ops)
    {
        if(startPos == num.size())
        {
            if(cumulativeValue == target)
                result.push_back(prevString);
            return ;
        }
        
        for(int i = startPos + 1; i <= num.size();i++)
        {
            string newStartString = num.substr(startPos, i - startPos);
            long long newStartValue = stol(newStartString);
            string newStarts = to_string(newStartValue);
            if(newStarts.size() != newStartString.size()) continue;
            dfs(num, target, result, prevString + '+' + newStartString, i, cumulativeValue + newStartValue, newStartValue,  '+');
            dfs(num, target, result, prevString + '-' + newStartString, i, cumulativeValue - newStartValue, newStartValue,  '-');
            dfs(num, target, result, prevString + '*' + newStartString, i, (ops == '-' ? cumulativeValue + preValue - preValue * newStartValue: ( ops == '+' ? cumulativeValue - preValue + preValue * newStartValue : preValue * newStartValue)), preValue * newStartValue, ops);
        }
        
    }
    vector<string> addOperators(string num, int target) {
        vector<string> result;
        if(num.empty()) return result;
        for(int i = 1;i <= num.size();i++)
        {
            string startString = num.substr(0, i);
            long long startValue = stol(startString);
            string startS = to_string(startValue);
            if(startS.size() != startString.size()) continue;
            dfs(num, target, result, startString, i, startValue, startValue, '#');
        }
        return result;
    }
};

/*

Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums. You are asked to burst all the balloons. If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins. Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.

Find the maximum coins you can collect by bursting the balloons wisely.

Note: 
(1) You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
(2) 0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100

Example:

Given [3, 1, 5, 8]

Return 167

    nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
   coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167
Credits:
Special thanks to @dietpepsi for adding this problem and creating all test cases.
*/
class Solution 
{
public:
    int maxCoins(vector<int>& nums)
    {
        num.insert(nums.begin(), 1); nums.insert(nums.end(), 1);
        int len = nums.size();
        vector<vector<int>> dp = vector<vector<int>>(len, vector<int>(len, 0));
        for(int l = 1; l <= len - 2; l++)
        {
            for(int i = 1;i < len - l - 1;i++)
            {
                int start = i, end = start + l - 1;
                for(int lastOne = start; lastOne <= end; lastOne++)
                {
                    dp[start][end] = max(dp[start][end], nums[start-1] * nums[lastOne] * nums[end + 1] + (lastOne != start ? dp[start][lastOne-1] : 0) + (lastOne != end ? dp[lastOne+1][end]: 0));
                }
            }
        }
        return dp[1][len-2];
    }
};

/*--------------End of Divide-And-Conquer-------------------*/

/*-------Start of Dynamic Programming and Memorization------*/
/*
Dynamic programming is mostly just a matter of taking recursive algorithm  and finding the overlapping subproblems(that is, the repeated calls). You then cache those results for future recursive calls
*/
/*Examples:

Leetcode 96. UniqueBinarySearchTrees
Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?
*/
/*Thought: The number of unique binary search tree is determined by how many sequence number do we have. When we have a sequence, every number could be a root node, then the sequence will be divided into two parts, left subtree, and right subtree, then our problem breaking down to to sub problem, how many unique BST each subtree could construct, this question could be done bottom-up */
//Bottome-up Solution
class Solution
{
public:
    int numTrees(int n)
    {
        vector<int> num(n + 1, 0);
        num[0] = num[1] = 1;
        for(int i = 2;i <= n;i++)
        {
            for(int leftN = 0; leftN < i;j++)
            {
                num[i] += num[j] * num[i - j -1];
            }
        }
        return num[n];
    }
};

/****SubSet Problem:****/
/*LeetCode 416. PartitionEqualSubSetSum
Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

Note:
Each of the array element will not exceed 100.
The array size will not exceed 200.
Example 1:

Input: [1, 5, 11, 5]

Output: true

Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: [1, 2, 3, 5]

Output: false

Explanation: The array cannot be partitioned into equal sum subsets.
*/

//Solution:
/*
As a standard Subset Problem question, it could be done by construct a matrix, the time complexity is O(NS), N is the size of the list, S is the target. 
*/
class Solution 
{
public:
    bool canPartition(vector<int>& nums)
    {
        int sum = 0;
        for(auto& n : nums)
            sum+=n;
        if(sum % 2 != 0)
            return false;
        int target = sum / 2;
        int n = nums.size();
        vector<vector<bool>> dp(target + 1, vector<bool>(n + 1, false));
        for(int i = 0;i <= n;i++)
            dp[0][i] = true;
        for(int i = 1;i <= target; i++)
        {
            for(int j = 1;j <= n;j++)
            {
                if(i > nums[j-1])
                    dp[i][j] = dp[i - nums[j-1]] || dp[i][j-1];
                else 
                    dp[i][j] = dp[i][j-1];
            }
        }
        return dp[target][n];
    }
};

//Complete knapsack problem 
/* Leetcode 322.CoinChange 

You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

Example 1:
coins = [1, 2, 5], amount = 11
return 3 (11 = 5 + 5 + 1)

Example 2:
coins = [2], amount = 3
return -1.

Note:
You may assume that you have an infinite number of each kind of coin.
*/

class Solution 
{
    public:
    int coinChange(vector<int>& coins, int amount)
    {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for(int i = 0;i <= amount;i++)
        {
            for(int j = 1;j <= coins.size(); j++)
            {
                if(i >= coins[j-1] && dp[i - coins[j-1]] != INT_MAX)
                    dp[i] = min(dp[i], dp[i- coins[j-1]] + 1);
            }
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};

//0 and 1 snackpack problem
/*
Leetcode 474. Ones and Zeros 
In the computer world, use restricted resource you have to generate maximum benefit is what we always want to pursue.

For now, suppose you are a dominator of m 0s and n 1s respectively. On the other hand, there is an array with strings consisting of only 0s and 1s.

Now your task is to find the maximum number of strings that you can form with given m 0s and n 1s. Each 0 and 1 can be used at most once.

Note:
The given numbers of 0s and 1s will both not exceed 100
The size of given string array won't exceed 600.
Example 1:
Input: Array = {"10", "0001", "111001", "1", "0"}, m = 5, n = 3
Output: 4

Explanation: This are totally 4 strings can be formed by the using of 5 0s and 3 1s, which are “10,”0001”,”1”,”0”
Example 2:
Input: Array = {"10", "0", "1"}, m = 1, n = 1
Output: 2

Explanation: You could form "10", but then you'd have nothing left. Better form "0" and "1".

*/
//Solution

class Solution 
{
    public:
    int findMaxForm(vector<string>& strs, int m ,int n)
    {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for(int i = 0;i < str.size();i++)
        {
            auto c = count(str[i]);
            for(int zero = m; zero >= c.first; zero--)
            {
                for(int one = n; zero >= c.second; one--)
                {
                    dp[zero][one] = max(dp[zero][one], dp[zero - c.first][one - c.second] + 1);
                }
            }
        }
        return dp[m][n];
    }

    pair<int,int> count(string word)
    {
        int zero = 0, one = 0;
        for(auto c : word)
        {
            if(c == '0')
                zero++;
            else 
                one++;
        }
        return make_pair(zero, one);
    }
};
/*-------End of Dynamic Programming and Memorization--------*/

/*--------------------Start Greedy -------------------------*/
/*
A greedy algorithm, always make the choice that seems to be the best at that moment. This means it makes a locally-optimal choice in the hope that this choice will lead to a globally-optimal solution
*/
/*
Examples:
Leetcode 55_JumpGame
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

Example 1:

Input: [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum
             jump length is 0, which makes it impossible to reach the last index.
*/

class Solution 
{
public:
    bool canJump(vector<int>& nums)
    {
        int lastOne = nums.size() - 1;
        for(int i = nums.size() - 2; i >= 0; i--)
        {
            if(nums[i] + i >= lastOne)
                lastOne = i;
        }
        return lastOne == 0;
    }
};

/*Leetcode 134 Gas Station
There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return -1.

Note:

If there exists a solution, it is guaranteed to be unique.
Both input arrays are non-empty and have the same length.
Each element in the input arrays is a non-negative integer.
Example 1:

Input: 
gas  = [1,2,3,4,5]
cost = [3,4,5,1,2]

Output: 3

Explanation:
Start at station 3 (index 3) and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 4. Your tank = 4 - 1 + 5 = 8
Travel to station 0. Your tank = 8 - 2 + 1 = 7
Travel to station 1. Your tank = 7 - 3 + 2 = 6
Travel to station 2. Your tank = 6 - 4 + 3 = 5
Travel to station 3. The cost is 5. Your gas is just enough to travel back to station 3.
Therefore, return 3 as the starting index.
Example 2:

Input: 
gas  = [2,3,4]
cost = [3,4,3]

Output: -1

Explanation:
You can't start at station 0 or 1, as there is not enough gas to travel to the next station.
Let's start at station 2 and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 0. Your tank = 4 - 3 + 2 = 3
Travel to station 1. Your tank = 3 - 3 + 3 = 3
You cannot travel back to station 2, as it requires 4 unit of gas but you only have 3.
Therefore, you can't travel around the circuit once no matter where you start.*/
class Solution 
{
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
        int start = 0, end = 0, more = 0, endmove = 0;
        while(endmove != cost.size())
        {
            more = more + gas[end] - cost[end];
            endmove++;
            while(move < 0)
            {
                more = more + cost[start] - gas[start];
                endmove--;
                start++;
                if(start == cost.size())
                    return -1;
            }
            end++;
            if(end == cost.size())
                end = 0;
        }
        return start;
    }
};

/*
LeetCode 406 Queue Reconstruction By height 

Suppose you have a random list of people standing in a queue. Each person is described by a pair of integers (h, k), where h is the height of the person and k is the number of people in front of this person who have a height greater than or equal to h. Write an algorithm to reconstruct the queue.

Note:
The number of people is less than 1,100.


Example

Input:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

Output:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
*/

bool mycompare(pair<int,int>& left, pair<int,int>& right)
{
    return left.first > right.first || left.second < right.second;
}

class Solution 
{
    public:
    vector<pair<int,int>> reconstructQueue<vector<pair<int,int>>& people)
    {
        vector<pair<int,int>> result;
        sort(people.begin(), people.second(), mycompare);

        for(auto & p : people)
        {
            result.insert(result.begin() + p.second, p);
        }

        return results;
    }
};

/*
Leetcode 621 Task Scheduler 
Given a char array representing tasks CPU need to do. It contains capital letters A to Z where different letters represent different tasks.Tasks could be done without original order. Each task could be done in one interval. For each interval, CPU could finish one task or just be idle.

However, there is a non-negative cooling interval n that means between two same tasks, there must be at least n intervals that CPU are doing different tasks or just be idle.

You need to return the least number of intervals the CPU will take to finish all the given tasks.

Example 1:
Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8
Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.
Note:
The number of tasks is in the range [1, 10000].
The integer n is in the range [0, 100].*/

class mycomparsion 
{
    public:
    bool operator()(const pair<char, int>& lhs, const pair<char, int>& rhs) const 
    {
        return lhs.second < rhs.second;
    }
};

class Solution 
{
    public:
    int leastInterval(vector<char>& tasks, int n)
    {
        unordered_map<char, int> dict;
        typedef priority_queue<pair<char, int>, vector<pair<char,int>>, mycomparsion> mypq;
        mypq pq;
        for(auto c : tasks)
        {
            dist[c]++;
        }
        for(auto& e : dict)
        {
            pq.emplace(e.first, e.second);
        }
        int count = 0;
        while(true)
        {
            vector<pair<char, int>> tmpv;
            for(int i = 0;i <=n ;i++)
            {
                if(pq.empty() && tmpv.size() == 0)
                    return count;
                else if(pq.empty() && tmpv.size() != 0)
                {
                    count++;
                }
                else if(!pq.empty())
                {
                    pair<char,int> tmp = pq.top();
                    pq.pop();
                    tmp.second--;
                    if(tmp.second != 0)
                        tmpv.push_back(tmp);
                    count++;
                }
            }
            for(auto p : tmpv)
            {
                pq.push(p);
            }
        }
    }
};
/*--------------------end Greedy ---------------------------*/
/*--------------------start Graph---------------------------*/
/*Graph is a data structure that consists of following two components:
1. A finite set of vertices also called as nodes.
2. A finite set of ordered pair of the form(u,v) called as edges. The pair is ordered because (u, v) is not same as (v, u) in case of directed graph. The pair of form(u,v) indicates that there is an edge from vertex u to vertex v. The edges may contain weight/value/cost. 
There are two most commonly used representations of graph:
1. Adjacent Matrix
2. Adjacent List

There are two ways to traverse graph:
1. DFS (Depth first search)
2. BFS (Breath first search)

Detected Cycle:
1. For undirected graph, we could use Union-find 
2. For directed graph, we could use topological Sort, and DFS
*/

//BFS 
/*Leetcode 133.CloneGraph
Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.


OJ's undirected graph serialization:
Nodes are labeled uniquely.

We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
As an example, consider the serialized graph {0,1,2#1,2#2,2}.

The graph has a total of three nodes, and therefore contains three parts as separated by #.

First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
Second node is labeled as 1. Connect node 1 to node 2.
Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
Visually, the graph looks like the following:

       1
      / \
     /   \
    0 --- 2
         / \
         \_/
*/
struct UndirectedGraphNode
{
    int label;
    vector<UndirectedGraphNode*> neighbors;
    UndirectedGraphNode(int x) : label(x){}
};
class Solution 
{
    public:
    UndirectedGraphNode*  cloneGraph(UndirectedGraphNode* node)
    {
        if(node == NULL)
            return NULL;
        queue<UndirectedGraphNode*> q;
        q.push(node);
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> m;
        m[node] = new UndirectedGraphNode(node->label);
        while(!q.empty())
        {
            int size = q.size();
            for(int i = 0;i < size;i++)
            {
                UndirectedGraphNode* parent = q.front();
                UndirectedGraphNode* cloneParent = m[parent];
                q.pop();
                for(auto child : parent->neighbors)
                {
                    if(m.count(child) == 0)
                    {
                        m[child] = new UndirectedGraphNode(child->label);
                        q.push(child);
                    }
                    cloneParent->neighbors.push_back(m[child]);
                }
            }
        }
        return m[node];
    }
};

//DFS 
/*Leetcode 802 Find Eventual Safe States
In a directed graph, we start at some node and every turn, walk along a directed edge of the graph.  If we reach a node that is terminal (that is, it has no outgoing directed edges), we stop.

Now, say our starting node is eventually safe if and only if we must eventually walk to a terminal node.  More specifically, there exists a natural number K so that for any choice of where to walk, we must have stopped at a terminal node in less than K steps.

Which nodes are eventually safe?  Return them as an array in sorted order.

The directed graph has N nodes with labels 0, 1, ..., N-1, where N is the length of graph.  The graph is given in the following form: graph[i] is a list of labels j such that (i, j) is a directed edge of the graph.

Example:
Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
Output: [2,4,5,6]
Here is a diagram of the above graph.

Illustration of graph

Note:

graph will have length at most 10000.
The number of edges in the graph will not exceed 32000.
Each graph[i] will be a sorted list of different integers, chosen within the range [0, graph.length - 1].*/

class Solution
{
    public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph)
    {
        vector<int> results;
        vector<bool> visited(graph.size(), false);
        vector<int> memory(graph.size(), -1);
        for(int i = 0;i < graphs.size();i++)
        {
            visited[i] = true;
            if(dfs(graph, visited, memory, i))
                result.push_back(i);
            visited[i] = false;
        }
        return result;
    }

    bool dfs(vector<vector<int>>& graph, vector<bool>& visited, vector<int>& memory, int cur)
    {
        if(memory[cur] != -1)
            return memory[cur] == 1;
        for(auto child : graph[cur])
        {
            if(visited[child] == true)
            {
                memory[cur] = 0;
                return false;
            }

            visited[child] = true;
            if(!dfs(graph, visited, memory, child))
            {
                memory[cur] = 0;
                visited[child] = false;
                return false;
            }
            visited[child] =false;
            
        }
        memory[cur] = 1;
        return true;
    }
};


//Union Find 
/*
Leetcode 261. Graph Valid Tree
Given n nodes labeled from 0 to n-1 and a list of undirected edges (each edge is a pair of nodes), write a function to check whether these edges make up a valid tree.

Example 1:

Input: n = 5, and edges = [[0,1], [0,2], [0,3], [1,4]]
Output: true
Example 2:

Input: n = 5, and edges = [[0,1], [1,2], [2,3], [1,3], [1,4]]
Output: false
Note: you can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0,1] is the same as [1,0] and thus will not appear together in edges.
*/

class Solution 
{
    public:
    bool validTree(int n, vector<pair<int,int>>& edges)
    {
        vector<int> array;
        for(int i = 0; i < n;i++)
        {
            array.push_back(array.size());
        }
        for(auto & edge : edges)
        {
            int left = edge.first;
            int right = edge.second; 
            while(array[left] != left)
            {
                left = array[left];
            }

            while(array[right] != right)
            {
                right =array[right];
            }

            if(left != right)
            {
                array[left] = right;
                n--;
            }
            else
                return false;
        }
        return n == 1;
    }
};

//Topological sort
/* Leetcode 210 Course Shedule 2
There are a total of n courses you have to take, labeled from 0 to n-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.

There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.

Example 1:

Input: 2, [[1,0]] 
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished   
             course 0. So the correct course order is [0,1] .
Example 2:

Input: 4, [[1,0],[2,0],[3,1],[3,2]]
Output: [0,1,2,3] or [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both     
             courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. 
             So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3] .
Note:

The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.
*/

class Solution 
{
    public:
    vector<int> findOrder(int numCourses, vector<pair<int,int>>& prerequisites)
    {
        vector<int> res;
        unordered_map<int, pair<int, vector<int>>> adj;
        for(int i = 0;i < numCoursers;i++)
        {
            adj[i].first = 0;
        }
        for(auto & link : prerequisites)
        {
            int in = link.second;
            int out = links.first;
            ad[in].second.push_back(out);
            ad[out].first++;
        }

        queue<int> start;
        for(auto ele : adj)
        {
            if(ele.second.first == 0)
                start.push(ele.first);
        }

        while(start.size() != 0)
        {
            int in = start.front();
            res.push_back(in);
            start.pop();
            for(auto & out : adj[in].second)
            {
                adj[out].first--;
                if(adj[out].first == 0)
                    start.push(out);
            }
            adj.erase(in);
        }
        if(adj.size() == 0)
            return res;
        else
            return vector<int>();
    }
};

/*---------------------end Graph ---------------------------*/

/*--------------------Binary Tree---------------------------*/
/*------------------- End Binary Tree-----------------------*/


int main(void)
{
    vector<int> unsortedArray = {1,5,2,3,3,3,3,3,3,3,2,2,2,2,2,2,3,7,3,45,3,7,8,2,35,74,9};
    //bubbleSort(unsortedArray);
    //SelectionSort(unsortedArray);    
    //insertionSort(unsortedArray);
    //mergeSort(unsortedArray);
    //quickSort(unsortedArray, 0, unsortedArray.size() - 1);
  
  nth_element(unsortedArray, 0, 4, unsortedArray.size() - 1);
    cout << unsortedArray[4] << endl;
    nth_element(unsortedArray, 0, 7, unsortedArray.size() - 1);
    cout << unsortedArray[7] << endl;
    for(auto n : unsortedArray)
    {
        cout << n << " " ;
    }
    cout << endl;
}
