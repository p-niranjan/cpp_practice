//https://leetcode.com/problems/subarray-sum-equals-k/description/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0, n = nums.size(), cnt = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        for(int num : nums) {
            sum += num;
            if(mp.find(sum - k) != mp.end())
                cnt += mp[sum - k];
            mp[sum]++;
        }
        return cnt;
    }
};
