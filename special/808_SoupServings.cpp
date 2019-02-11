/*
808. Soup Servings
DescriptionHintsSubmissionsDiscussSolution
There are two types of soup: type A and type B. Initially we have N ml of each type of soup. There are four kinds of operations:

Serve 100 ml of soup A and 0 ml of soup B
Serve 75 ml of soup A and 25 ml of soup B
Serve 50 ml of soup A and 50 ml of soup B
Serve 25 ml of soup A and 75 ml of soup B
When we serve some soup, we give it to someone and we no longer have it.  Each turn, we will choose from the four operations with equal probability 0.25. If the remaining volume of soup is not enough to complete the operation, we will serve as much as we can.  We stop once we no longer have some quantity of both types of soup.

Note that we do not have the operation where all 100 ml's of soup B are used first.  

Return the probability that soup A will be empty first, plus half the probability that A and B become empty at the same time.

 

Example:
Input: N = 50
Output: 0.625
Explanation: 
If we choose the first two operations, A will become empty first. For the third operation, A and B will become empty at the same time. For the fourth operation, B will become empty first. So the total probability of A becoming empty first plus half the probability that A and B become empty at the same time, is 0.25 * (1 + 1 + 0.5 + 0) = 0.625.

Notes:

0 <= N <= 10^9. 
Answers within 10^-6 of the true value will be accepted as correct.
*/
struct soup
{
    int A;
    int B;
    soup(int a, int b):A(a), B(b){}
};

struct soupHasher 
{
    size_t operator()(const soup& a) const  
    {
        return a.A *123 + a.B * 234;
    }
};

struct soupComparator
{
    bool operator()(const soup&a, const soup& b) const
    {
        return a.A == b.A && a.B == b.B;
    }
};

class Solution {
public:
    double soupServings(int N) {
        if(N % 25 != 0)
        {
            N = (N / 25 + 1) * 25;
        }
        unordered_map<soup, double, soupHasher, soupComparator> memo;
        double p;
        for(int i = 0;i <= N;i+=25)
        {
            p = helper(i, i, memo);
            if(((1.0 - p) / 1) < 1e-6)
            {
                return 1.0;
            }
        }
        return p;
    }
    double helper(int a, int b, unordered_map<soup, double, soupHasher, soupComparator>& memo)
    {
        soup s(a, b);
        if(memo.count(s) != 0)
        {
            return memo[s];
        }
        double p = 0; 
        if(a <= 0 && b > 0)
            p = 1.0;
        else if(a <= 0 && b <= 0)
            p = 0.5;
        else if(a > 0 && b <= 0)
        {
            p = 0.0;
        }else 
        {
            p = 0.25 * helper(a- 100, b, memo) + 0.25 * helper(a - 75, b - 25, memo) + 0.25 * helper(a - 50, b - 50, memo) + 0.25 * helper(a -25, b - 75, memo);
        }
        memo[s] = p;
        return p;
    }
};