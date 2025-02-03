// https://leetcode.com/problems/jump-game-ii/description/

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(), jumps = 0, farthest = 0, current_end = 0;
        for(int i = 0; i < n-1; i++)
        {
            farthest = max(farthest, i+nums[i]);
            if(current_end == i) {
                current_end = farthest;
                jumps++;
            }
            if(current_end >= n-1) break;
        }
        return jumps;
    }
};