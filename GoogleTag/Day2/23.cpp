/*
309. Best Time to Buy and Sell Stock with Cooldown
DescriptionHintsSubmissionsDiscussSolution
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:

You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
Example:

Input: [1,2,3,0,2]
Output: 3 
Explanation: transactions = [buy, sell, cooldown, buy, sell]
*/
class Solution 
{
public:
    int maxProfit(vector<int>& prices)
    {
        if(prices.size() == 0)
            return 0;
        int sellState = 0, earned = 0, have = 0, DontHave = 0, price = prices[0];
        int result = 0;
        for(int i = 1;i < prices.size();i++)
        {
            int yestardaySell = sellState;
            //maxProfit if I sell at today
            sellState = earned + prices[i] - price;
            if(DontHave - (prices[i] - price) > earned)
            {
                earned = DontHave;
                price = prices[i];
            }
            Donthave = max(DontHave, yestardaySell);
        }
        return max(sellState, DontHave);
    }
};