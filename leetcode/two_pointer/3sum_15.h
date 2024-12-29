// https://leetcode.com/problems/3sum/description/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> out{};
        int n = nums.size();
        for(int i  = 0; i < n-1; i++)
        {
            int l = i+1, r = n-1;
            while(l < r)
            {
				int sum = nums[i] + nums[l] + nums[r];
				if(sum == 0) {
					out.insert({nums[i], nums[l], nums[r]});
					l++;
					r--;
				} else if(sum < 0) {
					l++;
				} else {
					r--;
				}
            }
        }
        vector<vector<int>> s;
        s.insert(s.end(), out.begin(), out.end());
        return s;
    }
};