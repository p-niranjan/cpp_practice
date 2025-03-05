//https://leetcode.com/problems/combinations/description/?envType=study-plan-v2&envId=top-interview-150

class Solution {
    void helper(int start, const int n, const int k, vector<int> aux, vector<vector<int>>& out)
    {
        if(k == aux.size()) {
            out.push_back(aux);
            return;
        }

        for(int num = start; num <= n; num++) {
            aux.push_back(num);
            helper(num+1, n, k, aux, out);
            aux.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> out;
        vector<int> aux;
        helper(1, n, k, aux, out);
        return out;
    }
};
