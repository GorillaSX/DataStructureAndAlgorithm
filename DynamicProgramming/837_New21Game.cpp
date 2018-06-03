/*
Alice plays the following game, loosely based on the card game "21".

Alice starts with 0 points, and draws numbers while she has less than K points.  During each draw, she gains an integer number of points randomly from the range [1, W], where W is an integer.  Each draw is independent and the outcomes have equal probabilities.

Alice stops drawing numbers when she gets K or more points.  What is the probability that she has N or less points?

Example 1:

Input: N = 10, K = 1, W = 10
Output: 1.00000
Explanation:  Alice gets a single card, then stops.
Example 2:

Input: N = 6, K = 1, W = 10
Output: 0.60000
Explanation:  Alice gets a single card, then stops.
In 6 out of W = 10 possibilities, she is at or below N = 6 points.
Example 3:

Input: N = 21, K = 17, W = 10
Output: 0.73278
*/
class Solution {
public:
    double new21Game(int N, int K, int W) {
        if(K == 0 || K-1 + W <= N )
            return 1.0;
        vector<double> prob(N+1, 0);
        prob[0] = 1.0;
        double ProbSum = 1.0, res = 0.0;
        for(int i = 1;i <= N;i++)
        {
            prob[i] = ProbSum / W;
            if(i < K)
                ProbSum += prob[i];
            else 
                res += prob[i];
            if(i >= W)
                ProbSum -= prob[i-W];
        }
        return res; 
    }
};