class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1);
        dp[0] = 1;
        for(int x:coins){
            for(int j = 1; j<dp.size();j++){
            if(j >= x){
                dp[j] = dp[j] + dp[j-x];
                }
            }
        }
    return dp[amount];
    }
};