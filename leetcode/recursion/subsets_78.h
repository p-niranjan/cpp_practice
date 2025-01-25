// https://leetcode.com/problems/subsets/description/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> out;
        vector<int> aux;
        int n = nums.size();
        subsetsHelper(0, n, nums, aux, out);
        return out;
    }

    void subsetsHelper(int idx, int n, vector<int>& nums, vector<int>& aux, vector<vector<int>>& out)
    {
        if(idx == n) {
            out.push_back(aux);
            return;
        }
        aux.push_back(nums[idx]);
        subsetsHelper(idx+1, n, nums, aux, out);
        aux.pop_back();
        subsetsHelper(idx+1, n, nums, aux, out);
    }
};