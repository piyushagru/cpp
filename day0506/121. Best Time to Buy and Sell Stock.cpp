/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/discuss/108870/Most-consistent-ways-of-dealing-with-the-series-of-stock-problems/213087/https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/discuss/108870/Most-consistent-ways-of-dealing-with-the-series-of-stock-problems/213087/
*/

THIS SOLUTION GIVES TLE
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0)return 0;
        vector<int> dp(prices.size(),0);
        int max = 0,temp = 0;
        dp[0] = 0;
        
        
        for(int i = 0;i<prices.size();i++){
            int taken = prices[i];
            for(int j = i+1;j<prices.size();j++){
                temp = prices[j] - taken;
                if(temp > max)
                    max = temp;
                
            }
            dp[i] = max;
        }
    return *max_element(dp.begin(),dp.end());
    }
};



//acording to the article link given above 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int t_ik0 = 0; //0 stock at the end of the day (sell or rest)
        int t_ik1 = INT_MIN; //1 stock at the end of the day (buy or rest)
        for(int i = 0;i<prices.size();i++){
            t_ik0 = max(t_ik0,t_ik1 + prices[i]);//rest, sell stock
            t_ik1 = max(t_ik1, -prices[i]);
        }
    return t_ik0; //we always have larger profit if we end up with 0 stock in hand
    }
};