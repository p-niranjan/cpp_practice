// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0], maxProfit = 0, n = prices.size();
        for(int i = 1; i < n; i++) 
        {
            int profitOnCurDay = prices[i] - mini;
            maxProfit = max(profitOnCurDay, maxProfit);
            mini = min(mini, prices[i]);
        }
        return maxProfit;
    }
};