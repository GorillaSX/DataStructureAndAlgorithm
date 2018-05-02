/*
There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?

Example 1:

Input: [1,0,2]
Output: 5
Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.
Example 2:

Input: [1,2,2]
Output: 4
Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
             The third child gets 1 candy because it satisfies the above two conditions.
*/
class Solution {
public:
    int candy(vector<int>& ratings) {
        if(ratings.size()  == 1)
            return 1;
        int amount = 0;
        int ascending = 0;
        int decending = 0;
        bool reset = true;
        for(int i = 1;i < ratings.size();i++)
        {

            if(reset && ratings[i] > ratings[i-1])
                ascending++;
            else if(reset == false && ratings[i] > ratings[i- 1])
            {
                if(ascending >= decending)
                {
                    amount += (1 + ascending + 1) * (ascending + 1) / 2;
                    decending = decending - 2;
                    amount += (2 + decending + 2) * (decending + 1) / 2;
                }
                else 
                {
                    if(ascending != 0)
                    {
                        ascending--;
                        amount += (1 + ascending + 1) * (ascending + 1) / 2;
                    }
                    amount += (2 + decending + 1) * (decending) / 2;
                }
                reset = true;
                ascending = 0;
                decending = 0;
                ascending++;
            }
            else if(ratings[i] < ratings[i-1])
            {
                reset = false;
                decending++;
            }
            else if(ratings[i] == ratings[i-1])
            {
                if(ascending == decending  && decending == 0)
                {
                    amount += 1;
                }
                else
                {
                    if(ascending >= decending)
                    {
                        amount += ((1 + ascending+1) * (ascending + 1))/ 2 ;
                        if(decending != 0)
                        {
                            decending--;
                            amount += ((1 + decending + 1) * (decending + 1)) / 2;
                        }
                    }
                    else 
                    {
                        amount += ((1 + decending + 1) * (decending + 1)) / 2;
                        ascending--;
                        amount += ((1 + ascending + 1) * (ascending + 1)) / 2;
                    }
                }
                reset = true;
                ascending = 0;
                decending = 0;
            }
        }
        if(reset == true)
        {
            amount += ((1 + ascending + 1) * ( ascending+1)) / 2;
        }
        else
        {
            if(ascending >= decending)
            {
                amount += ((1 + ascending+1) * (ascending + 1))/ 2 ;
                if(decending != 0)
                {
                    decending--;
                    amount += ((1 + decending + 1) * (decending + 1)) / 2;
                }
            }
            else 
            {
                amount += ((1 + decending + 1) * (decending + 1)) / 2;
                ascending--;
                amount += ((1 + ascending + 1) * (ascending + 1)) / 2;
            }

        }
        return amount;
    }
};