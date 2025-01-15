// https://leetcode.com/problems/daily-temperatures/description/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        const int n = temperatures.size();
        vector<int> out(n, 0);
        stack<int> stk;
        for(int i = n-1; i >= 0; i--)
        {
            while(!stk.empty() && temperatures[i] >= temperatures[stk.top()]) stk.pop();
            if(!stk.empty()) out[i] = stk.top()-i;
            stk.push(i);
        }
        return out;
    }
};