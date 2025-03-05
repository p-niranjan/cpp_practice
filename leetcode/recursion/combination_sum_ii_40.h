//https://leetcode.com/problems/combination-sum-ii/description/

class Solution {
private:
    void helper(int idx,
                const vector<int>& candidates,
                int target, 
                vector<int> &aux,
                vector<vector<int>> &out)
    {
        const int n = candidates.size();
        if(n == idx) {
            if(0 == target) out.push_back(aux);
            return;
        }

        if(target >= candidates[idx]) {
            aux.push_back(candidates[idx]);
            helper(idx+1, candidates, target-candidates[idx], aux, out);
            aux.pop_back();
        }
        while(idx+1 < n && candidates[idx] == candidates[idx+1])
            idx++;        
        helper(idx+1, candidates, target, aux, out);
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> out;
        vector<int> aux;
        helper(0, candidates, target, aux, out);
        return out;
    }
};
