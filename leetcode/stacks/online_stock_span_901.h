// https://leetcode.com/problems/online-stock-span/?envType=study-plan-v2&envId=leetcode-75

class StockSpanner {
    vector<int> arr;
    stack<pair<int, int>> stk;
    int index;
public:
    StockSpanner() {
        index = -1;
        while(!stk.empty()) stk.pop();
    }
    
    int next(int price) {
        index++;
        while(!stk.empty() && price >= stk.top().first) stk.pop();
        int ans = index - (stk.empty() ? -1 : stk.top().second);
        stk.push({price, index});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */