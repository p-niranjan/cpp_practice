//https://leetcode.com/problems/combination-sum/description/

using combos = vector<vector<int>>;
using combo = vector<int>;
class Solution {
    void helper(int idx, const vector<int>& arr, int tgt, vector<int> aux, combos& out)
    {
        if(arr.size() == idx) {
            if(tgt == 0) out.push_back(aux);
            return;
        }
        // not take the cur element        
        helper(idx+1, arr, tgt, aux, out);

        // take the cur element
        if(tgt >= arr[idx]) {
            aux.push_back(arr[idx]);
            helper(idx, arr, tgt-arr[idx], aux, out);
        }        
    } 
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        combos out;
        combo aux;
        helper(0, candidates, target, aux, out);
        return out;
    }
};
