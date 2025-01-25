// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        dp[n][0] = dp[n][1] = 0;
        for(int i = n-1; i >=0; i--) {            
            for(int j = 0; j < 2; j++) {
                if(j == 1) {
                    int tk = -prices[i] + dp[i+1][0];
                    int ntk = 0 + dp[i+1][1];
                    dp[i][j] = max(tk, ntk);
                } else {
                    int tk = prices[i] + dp[i+1][1];
                    int ntk = 0 + dp[i+1][0];
                    dp[i][j] = max(tk, ntk);
                }
            }
        }
        return dp[0][1];
    }
};