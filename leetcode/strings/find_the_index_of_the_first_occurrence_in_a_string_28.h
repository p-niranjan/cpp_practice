//https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/?envType=study-plan-v2&envId=top-interview-150

class Solution {
private:
    int sum(vector<int>& gas) {
        int sum = 0;
        for(int val : gas) sum += val;
        return sum;
    }
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if(sum(gas) < sum(cost)) return -1;
        int startIdx = 0, totalCost = 0, n = gas.size();
        for(int i = 0; i < n; i++) {
            totalCost += gas[i] - cost[i];
            if(totalCost < 0) {
                totalCost = 0;
                startIdx = i+1;
            }
        }
        return totalCost >= 0 ? startIdx : -1;
    }
};
