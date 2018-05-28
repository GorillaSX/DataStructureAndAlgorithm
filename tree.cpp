#include <iostream>
#include <stack>
using namespace std;

struct TNode
{
    int val;
    TNode* left;
    TNode* right;
    TNode(int v):val(v),left(NULL),right(NULL){}
};


//Inorder Traverse
//Using Recursive
void PrintInorderRecursive(TNode* root)
{
    if(root == NULL)
        return ;
    PrintInorderRecursive(root->left);
    cout << root->val << endl;
    PrintInorderRecursive(root->right);
}

//Using Stack + Iterative
void PushNodeToStackForInorder(stack<TNode*>& nodeStack, TNode* root)
{
    while(root != NULL)
    {
        nodeStack.push(root);
        root = root->left;
    }
}
void PrintInorderIterative(TNode* root)
{
    if(root == NULL)
        return ;
    stack<TNode*> nodeStack;
    PushNodeToStackForInorder(nodeStack, root);

    while(!nodeStack.empty())
    {
        TNode* tmp = nodeStack.top();
        nodeStack.pop();
        cout << tmp->val << endl;
        PushNodeToStackForInorder(nodeStack, tmp->right);
    }

}
//O(n) time, O(1) space Morris Traverse
void PrintInorderMorris(TNode* root)
{
    if(root == NULL)
        return; 
    while(root != NULL)
    {
        if(root->left == NULL)
        {
            cout << root->val << endl;
            root = root->right;
        }
        else
        {
            TNode* left  = root->left;
            while(left->right != NULL && left->right != root)
                left = left->right;
            
            if(left->right == root)
            {
                left->right = NULL;
                cout << root->val << endl;
                root = root->right;
            }
            else if(left->right == NULL)
            {
                left->right = root;
                root = root->left;
            }
            
        }
    }
    
}

//Preorder
//Recursion
void PrintPreorderRecursive(TNode* root)
{
    if(root == NULL)
        return ;
    cout << root->val << endl;
    PrintPreorderRecursive(root->left);
    PrintPreorderRecursive(root->right);
}
//Stack + Iterative
void PrintPreorderIterative(TNode* root)
{
    if(root == NULL)
        return ;
    stack<TNode*> nodeStack;
    nodeStack.push(root);
    while(!nodeStack.empty())
    {
        TNode* tmp = nodeStack.top();
        nodeStack.pop();
        cout << tmp->val << endl;
        if(tmp->right != NULL)
            nodeStack.push(tmp->right);
        if(tmp->left != NULL)
            nodeStack.push(tmp->left);
    }
}
//Morris O(n) time O(1) space
void PrintPreorderMorris(TNode* root)
{
    if(root == NULL)
        return ;
    while(root != NULL)
    {
        if(root->left != NULL)
        {
            TNode* left = root->left;
            while(left->right != NULL and left->right != root)
                left = left->right;
            if(left->right == NULL)
            {
                cout << root->val << endl;
                left->right = root;
                root = root->left;
            }
            else if(left->right == root)
            {
                left->right = NULL;
                root = root->right;
            }
        }
        else
        {
            cout << root->val << endl;
            root = root->right;
        }
    }
}



//PostOrder
//Recursive
void PrintPostOrderRecursive(TNode* root)
{
    if(root == NULL)
        return ;
    PrintPostOrderRecursive(root->left);
    PrintPostOrderRecursive(root->right);
    cout << root->val << endl;
}
//Iterative + stack
void PushNodeToStackForPostOrder(stack<TNode*>& nodeStack, TNode* root)
{
    while(root != NULL)
    {
        if(root->right != NULL)
            nodeStack.push(root->right);
        nodeStack.push(root);
        root = root->left;
    }
}

void PrintPostOrderIterative(TNode* root)
{
    if(root == NULL)
        return;
    stack<TNode*> nodeStack;
    PushNodeToStackForPostOrder(nodeStack, root);
    while(!nodeStack.empty())
    {
        TNode* tmp = nodeStack.top();
        nodeStack.pop();
        if(!nodeStack.empty() && tmp->right == nodeStack.top())
        {
            TNode* r = nodeStack.top();
            nodeStack.pop();
            nodeStack.push(tmp);
            PushNodeToStackForPostOrder(nodeStack, r);
        }
        else
        {
            cout << tmp->val << endl;
        }
    }
}
//Morris Traversal O(n) time, O(1) space
void ReverseNode(TNode* from, TNode* to)
{
    TNode* x = from, *y = from->right, *z = NULL;
    while(true)
    {
        z = y->right;
        y->right = x;
        x = y;
        y = z;
        if(x == to)
            break;
    }
}
void Print(TNode* from, TNode* to)
{
    while(true)
    {
        cout << from->val << endl;
        if(from == to)
            break;
        from = from->right;
    }
}
void PrintReverse(TNode* from, TNode* to)
{
    if(from == to)
    {
        cout << from->val << endl;
        return ;
    }
    else
    {
        ReverseNode(from, to);
        Print(to, from);
        ReverseNode(to, from);
    }
}
void PrintPostOrderMorris(TNode* root)
{
    if(root == NULL)
        return ;
    TNode dump(0);
    dump.left = root;
    root = &dump;
    while(root != NULL)
    {
        if(root->left == NULL)
        {
            root = root->right;
        }
        else
        {
            TNode* left = root->left;
            while(left->right != NULL && left->right != root)
                left = left->right;
            if(left->right == NULL)
            {
                left->right = root; 
                root = root->left;
            }
            else if(left->right == root)
            {
                left->right = NULL;
                PrintReverse(root->left, left);
                root = root->right;
            }
        }
    }
}
// Binary Index Tree
/*Binary Indexed Tree is represented by an array, each node is accessed by it's index. And the index of it's parent node and child node could be calculate by using bit manipulation. */
/*The index of a binary indexed tree, should start with 1*/
/*Example:
Leetcode 315_RangeSumQuery-Mutable
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

The update(i, val) function modifies nums by updating the element at index i to val.
Example:
Given nums = [1, 3, 5]

sumRange(0, 2) -> 9
update(1, 2)
sumRange(0, 2) -> 8
Note:
The array is only modifiable by the update function.
You may assume the number of calls to update and sumRange function is distributed evenly.
*/

class NumArray 
{
    public:
    vector<int> m_sums;
    vector<int> m_nums;
    NumArray(vector<int> nums)
    {
        m_nums = vector<int>(nums.size(), 0);
        m_sums = vector<int>(nums.size() + 1, 0);
        for(int i = 0;i < num.size();i++)
        {
            update(i, nums[i]);
        }
    }

    void update(int i, int val)
    {
        int updateValue = val - m_nums[i];
        m_nums[i] = val;
        ++i;
        while(i < m_sums.size())
        {
            m_sums[i] += updateValue;
            i += (i & -i);
        }
    }

    int sum(int i )
    {
        int sum = 0;
        ++i;
        while(i > 0)
        {
            sum += m_sums[i];
            i -= (i & -i);
        }
        return sums;
    }

    int sumRange(int i, int j)
    {
        return sum(j) - sum(i-1);
    }
};
//Example
/*
LeetCode 315 CountOfSmallerNumbersAfterSelf

You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].

Example:

Given nums = [5, 2, 6, 1]

To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.
Return the array [2, 1, 1, 0].
*/

//Solution thought:
/*
After sort the given array, we can compare two elements by just compare their index in the sorted array. Thus if we want to calculate how many elements smaller, we just need to count how many elements which the index smaller the given elements index.
*/

class Solution 
{
    public:
    void update(vector<int>& bit, int index, int value)
    {
        while(index < bit.size())
        {
            bit[index] += value;
            i += (i & -i);
        }
    }

    int sum(vector<int>& bit, int index)
    {
        int sum = 0;
        while(index > 0)
        {
            sum += bit[index];
            index -= (index & -index);
        }
        return sum;
    }
    vector<int> countSmaller(vector<int>& nums)
    {
        vector<int> result(nums.size() ,0);
        if(nums.size() == 0)
            return results;
        vector<int> sorted(nums);
        sort(sorted.begin(), sorted.end());
        unordered_map<int, int> indexmap;
        for(int i = 0;i < sorted.size();i++)
        {
            indexmap[sorted[i]] = i + 1;
        }
        vector<int> bit = vector<int>(sorted.size() + 1, 0);
        for(int i = 0;i < nums.size() - 1;i--)
        {
            result[i] = sum(bit, indexmap[nums[i]] - 1);
            update(bit, indexmap[nums[i]], 1);
        }
        return results;
    }
};

//Trie 
/*Implement a Trie with insert, search, and startWith methods.
Note: you may assume that all inputs are consist of lowercase letters a-z
*/
class Trie 
{
public:
    Trie* child[26];
    bool end = false;
    Trie()
    {
        for(int i = 0;i < 26;i++)
            child[i] = NULL;
    }

    void insert(string word)
    {
        Trie* tmp = this;
        for(int i = 0;i < word.size();i++)
        {
            if(tmp->child[word[i] - 'a'] == NULL)
                tmp->child[word[i]-'a'] = new Trie();
            tmp = tmp->child[word[i] - 'a'];
        }
        tmp->end = true;
    }

    bool search(string word)
    {
        Trie* node = this;
        for(int i = 0;i < word.size();i++)
        {
            if(node->child[word[i]-'a'] == NULL)
                return false;
            else
                node = node->child[word[i] - 'a'];
        }
        return node->end;
    }

    bool startWith(string word)
    {
        Trie* node = this;
        for(int i = 0;i < word.size();i++)
        {
            if(node->child[word[i] - 'a'] == NULL)
                return false;
            else
                node = node->child[word[i] - 'a'];
        }
        return true;
    }
};
/*
Given a 2D board and a list of words from the dictionary, find all words in the board.

Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

For example,
Given words = ["oath","pea","eat","rain"] and board =

[
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]
Return ["eat","oath"].
*/
class Trie 
{
    public:
    Trie(){}
    void insert(string word)
    {
        Trie* node = this;
        for(int i = 0;i < word.size();i++)
        {
            if(node->child[word[i] - 'a'] == NULL)
                node->child[word[i] - 'a'] = new Trie();
            node = node->child[word[i] - 'a'];
        }
        node->word = word;
    }
    Trie* child[26] = {NULL};
    string word = "";
};

void search(vector<vector<bool>>& visited, unordered_map<string>& result, int i , int j, vector<vector<char>>& board, Trie* node)
{
    int delta[5] = {0, -1, 0 ,1, 0};
    int m = board.size();
    int n = m ? board[0].size() : 0;
    if(node->word != "")
        result.insert(node->word);
    for(int index = 0;index < 4; index++)
    {
        int row = i + delta[index];
        int col = j + delta[index+1];
        if(row >= 0 and row < m and col >= 0 and col < n and visited[row][col] == false && node->child[board[row][col] - 'a'] != NULL)
        {
            visited[row][col] = true;
            search(visited, result, row, col, board, node->child[board[row][col] - 'a']);
            visited[row][col] = false;
        }
    }
}

class Solution 
{
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words)
    {
        int m = board.size();
        int n = m ? board[0].size() : 0;
        vector<vector<bool>> visited(m, vector<bool>(n , false));
        Trie root;
        for(auto & word : words)
            root.insert(word);
        unordered_set<string> result;
        for(int i = 0;i < m;i++)
        {
            for(int j = 0;j < n;j++)
            {
                if(root.child[board[i][j] - 'a'] != NULL)
                {
                    visited[i][j] = true;
                    search(visited, result, i, j, board, root.child[board[i][j] - 'a']);
                    visited[i][j] = false;
                }
            }
        }
        vector<string> res(result.begin(), result.end());
        return res;
    }
};

//Example
/*421_MaximumXORofTwoNumbersInAnArray
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
    Trie* member[2] = {NULL};
    Trie(){}
    void insert(int number)
    {
        Trie* node = this;
        for(int i = 31;i >= 0;i--)
        {
            int index = (number >> i) & 1;
            if(node->member[index] == NULL)
                node->member[index] = new Trie();
            node = node->member[index];
        }
    }

    int query(int number)
    {
        Trie* node = this;
        int results = 0;
        for(int i = 31;i >= 0 ;i--)
        {
            int index = ((number >> i) & i) == 1 ? 0 : 1;
            if(node->member[index] != NULL)
            {
                result += (1 << i);
                node = node->member[index];
            }
            else
            {
                node = node->member[1 - index];
            }
        }
        return result;
    }
};

class Solution 
{
    public:
    int findMaximumXOR(vector<int>& nums)
    {
        Trie* root = new Trie();
        int res = 0;
        for(auto n : nums)
            root->insert(n);
        for(auto n : nums)
        {
            res = max(res, root->query(n));
        }
        return res;
    }
};

//Segment Tree
class SegmentTree
{
    SegmentTree(vector<int> input)
    {
        int x = (int)(ceil(log2(n)));
        int max_size = 2 * (int)pow(2, x);
        Tree = vector<int>(max_size, 0);
        build(1, 0, input.size() - 1);
    }

private:
    void build(int node, int start, int end)
    {
        if(start == end)
        {
            Tree[node] = Array[start];
        }
        else
        {
            int mid = (start + end) / 2;
            build(node*2, start, mid);
            build(node*2 + 1, mid + 1, end);
            Tree[node] = Tree[node*2] + Tree[node*2+1];
        }
    }
    void update(int node, int start, int end, int idx, int val)
    {
        if(start == end)
        {
            Tree[node] += val;
            Array[idx] += val;
        }
        else
        {
            int mid = (start + end) / 2;
            if(idx >= start  && idx <= mid)
                update(2 * node, start, mid, idx, val);
            else 
                update(2 * node + 1, mid + 1, end, idx, val);
        }
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    int query(int node, int start, int end, int l, int r)
    {
        if(l <= start and r >= end)
        {
            return Tree[node];
        }
        else if(r < start && l > end)
        {
            return 0;
        }
        else
        {
            int mid = (start + end)/ 2;
            int left = query(node * 2, start, mid, l, r);
            int right = query(node*2 + 1, mid + 1, end, l, r);
            return left + right;
        }
    }
    vector<int> Tree;
    vector<int> Array;
};


//A Tree, which node is a range
/*
Implement a MyCalendarThree class to store your events. A new event can always be added.

Your class will have one method, book(int start, int end). Formally, this represents a booking on the half open interval [start, end), the range of real numbers x such that start <= x < end.

A K-booking happens when K events have some non-empty intersection (ie., there is some time that is common to all K events.)

For each call to the method MyCalendar.book, return an integer K representing the largest integer such that there exists a K-booking in the calendar.

Your class will be called like this: MyCalendarThree cal = new MyCalendarThree(); MyCalendarThree.book(start, end)
Example 1:
MyCalendarThree();
MyCalendarThree.book(10, 20); // returns 1
MyCalendarThree.book(50, 60); // returns 1
MyCalendarThree.book(10, 40); // returns 2
MyCalendarThree.book(5, 15); // returns 3
MyCalendarThree.book(5, 10); // returns 3
MyCalendarThree.book(25, 55); // returns 3
Explanation: 
The first two events can be booked and are disjoint, so the maximum K-booking is a 1-booking.
The third event [10, 40) intersects the first event, and the maximum K-booking is a 2-booking.
The remaining events cause the maximum K-booking to be only a 3-booking.
Note that the last event locally causes a 2-booking, but the answer is still 3 because
eg. [10, 20), [10, 40), and [5, 15) are still triple booked.
Note:

The number of calls to MyCalendarThree.book per test case will be at most 400.
In calls to MyCalendarThree.book(start, end), start and end are integers in the range [0, 10^9].
*/

struct STreeNode
{
    STreeNode(int s, int e, int c = 1):start(s), end(e), left(NULL), right(NULL), count(c){}
    int start, end;
    int count;
    int insert(STreeNode*& root)
    {
        if(root == NULL)
        {
            root = this;
            return root->count;
        }
        else if(start >= root->end)
            return this->insert(root->right);
        else if(end <= root->start)
            return this->insert(root->left);
        else 
        {
            int leftreturn = 0, rightreturn = 0;
            if(start < root->start)
            {
                STreeNode* newleft = new STreeNode(start, root->start);
                leftreturn = newleft->insert(root->left);
            }
            else if(start > root->start)
            {
                STreeNode* newleft = new STreeNode(root->start, start, root->count);
                newleft->left = root->left;
                root->left = newleft;
                root->start = start;
            }

            if(end > root->end)
            {
                STreeNode* newright = new STreeNode(root->end, end);
                rightreturn = newright->insert(root->right);
            }
            else if(end < root->end)
            {
                STreeNode* newright = new STreeNode(end, root->end, root->count);
                newright->right = root->right;
                root->right = newright;
                root->end = end;
            }
            ++(root->count);
            return max(leftreturn, max(root->count, rightreturn));
        }
    }
    STreeNode* left, * right;
};
class MyCalendarThree
{
    STreeNode* root;
    int curCount;
    MyCalendarThree():root(NULL), curCount(0){}

    int book(int start, int end)
    {
        STreeNode* node = new STreeNode(start, end);
        int count = node->insert(root);
        curCount = max(count, curCount);
        return curCount;
    }
};

//Heap
/* Leetcode 373 Find K pairs with smallest Sums*/
/*
You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.

Define a pair (u,v) which consists of one element from the first array and one element from the second array.

Find the k pairs (u1,v1),(u2,v2) ...(uk,vk) with the smallest sums.

Example 1:
Given nums1 = [1,7,11], nums2 = [2,4,6],  k = 3

Return: [1,2],[1,4],[1,6]

The first 3 pairs are returned from the sequence:
[1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
Example 2:
Given nums1 = [1,1,2], nums2 = [1,2,3],  k = 2

Return: [1,1],[1,1]

The first 2 pairs are returned from the sequence:
[1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
Example 3:
Given nums1 = [1,2], nums2 = [3],  k = 3 

Return: [1,3],[2,3]

All possible pairs are returned from the sequence:
[1,3],[2,3]*/

class comp 
{
public:
    bool operator(const pair<pair<int,int>, int>& lhs, const pair<pair<int,int>, int>& rhs) const
    {
        return lhs.second > rhs.second;
    }
};

class Solution 
{
public:
    vector<pair<int,int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k)
    {
        typedef priority_queue<pair<pair<int,int>, int>, vector<pair<pair<int,int>, int>>, comp> pq;
        vector<pair<int,int>> results;
        pq mypq;
        mypq.push(make_pair(make_pair(0,0),nums1[0] + nums2[0]));
        int count = 0;
        set<pair<int,int>> visited;
        while(count != k && !mypq.empty())
        {
            auto tmp = mypq.top();
            mypq.pop():
            if(visited.count(tmp.first) == 0)
            {
                visited.insert(tmp.first);
                result.push_back(make_pair(nums1[tmp.first.first], nums2[tmp.first.second]));
                if(tmp.first.second + 1 < nums.size())
                    mypq.push(make_pair(make_pair(tmp.first.first, tmp.first.second + 1), nums1[tmp.first.first] + nums2[tmp.first.second + 1]));
                if(tmp.first.first + 1 < nums1.size())
                {
                    mypq.push_back(make_pair(make_pair(tmp.first.first+1, tmp.first.second), nums1[tmp.first.first+1] + nums2[tmp.first.second]));
                }
                count++;
            }
        }
        return results;
    }
};



int main(void)
{
    TNode* root = new TNode(1);
    root->left = new TNode(2);
    root->right = new TNode(3);
    root->left->left = new TNode(-1);
    root->right->left = new TNode(4);
    root->left->right = new TNode(3);
    root->left->right->left = new TNode(4);
    root->right->left->right = new TNode(7);
    cout << "inorder" << endl;
    PrintInorderRecursive(root);
    cout << "inorder" << endl;
    PrintInorderIterative(root);
    cout << "inorder" << endl;
    PrintInorderMorris(root);
    cout << "preorder" << endl;
    PrintPreorderIterative(root);
    cout << "preorder" << endl;
    PrintPreorderRecursive(root);
    cout << "preorder" << endl;
    PrintPreorderMorris(root);
    cout << "postOrder" << endl;
    PrintPostOrderRecursive(root);
    cout << "postOrder" << endl;
    PrintPostOrderIterative(root);
    cout << "PostOrder" << endl;
    PrintPostOrderMorris(root);
}
