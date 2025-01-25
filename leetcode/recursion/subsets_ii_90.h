// https://leetcode.com/problems/subsets-ii/description/

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> aux;
        vector<vector<int>> out;
        int n = nums.size();
        helper(0, n, nums, aux, out);
        return out;
    }

    void helper(int idx, int n, vector<int>& nums, vector<int>& aux, vector<vector<int>>& out)
    {
        if(idx == n) {
            out.push_back(aux);
            return;
        }
        aux.push_back(nums[idx]);
        helper(idx+1, n, nums, aux, out);
        aux.pop_back();
        while(idx+1 < n && nums[idx] == nums[idx+1]) idx++;
        helper(idx+1, n, nums, aux, out);
    }
};