// https://leetcode.com/problems/total-cost-to-hire-k-workers/?envType=study-plan-v2&envId=leetcode-75

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int, vector<int>, greater<int>> first, last;
        int n = costs.size(), j = n-1, i = 0;
        long long total = 0;
        while(k > 0) 
        {
            while(first.size() < candidates && i <= j) first.push(costs[i++]);
            while(last.size() < candidates && i <= j) last.push(costs[j--]);

            int t1 = first.size() > 0 ? first.top() : INT_MAX;
            int t2 = last.size() > 0 ? last.top() : INT_MAX;

            if(t1 <= t2) {
                total += t1;
                first.pop();
            } else {
                total += t2;
                last.pop();
            }
            k--;
        }
        return total;
    }
};