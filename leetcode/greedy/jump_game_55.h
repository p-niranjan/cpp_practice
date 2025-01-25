// https://leetcode.com/problems/jump-game/description/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), maxReach = 0;
        for(int i = 0; i < n; i++) {
            if(i > maxReach) return false;
            maxReach = max(maxReach, i+nums[i]);
            if(maxReach >= n-1) return true;
        }
        return false;
    }
};