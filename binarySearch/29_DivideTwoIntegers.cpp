/*
Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT.
*/

class Solution 
{
    public:
        int divide(int dividend, int divisor)
        {
           if(!divisor || (dividend == INT_MIN && divisor == -1))  
                return INT_MAX;
            int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;
            long long dvd = labs(dividend);
            long long dvs = labs(divisor);
            int res = 0;
            while(dvd >= dvs)
            {
                long long count = 1;
                long long tmp = dvs;
                while(dvd >= (tmp << 1))
                {
                    count <<= 1;
                    tmp <<= 1;
                }
                res += count;
                dvd -= tmp;
            }
            return sign == -1 ? -res : res; 
        }
};