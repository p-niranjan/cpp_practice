//https://leetcode.com/problems/two-sum/description/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> out(2);
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++) mp[nums[i]] = i;

        for(int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            int diff = target - num;
            printf("num = %d, diff = %d\n", num, diff);
            if(mp.find(diff) != mp.end() && i != mp[diff]) {
                out[0] = i;
                out[1] = mp[diff];
                break;
            }
        }
        return out;
    }
};
