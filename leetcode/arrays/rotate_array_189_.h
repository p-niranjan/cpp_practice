// https://leetcode.com/problems/rotate-array/description/?envType=study-plan-v2&envId=top-interview-150
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // RLKFNK
        int n = nums.size();
        k = k % n;
        reverse(nums.end()-k, nums.end());
        reverse(nums.begin(), nums.begin()+n-k);
        reverse(nums.begin(), nums.end());
    }
};