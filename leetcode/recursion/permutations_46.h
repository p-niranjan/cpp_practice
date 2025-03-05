//https://leetcode.com/problems/permutations/description/

class Solution {
private:
    void helper(int idx, vector<int>& nums, vector<vector<int>> &out) {
        const int n = nums.size();
        if(n == idx) {
            out.push_back(nums);
            return;
        }

        for(int i = idx; i < n; i++) {
            swap(nums[i], nums[idx]);
            helper(idx+1, nums, out);
            swap(nums[i], nums[idx]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> out;
        helper(0, nums, out);
        return out;
    }
};
