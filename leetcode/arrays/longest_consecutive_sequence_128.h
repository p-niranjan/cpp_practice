// https://leetcode.com/problems/longest-consecutive-sequence/description/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;

        unordered_set<int> s(nums.begin(), nums.end());
        int maxlen = 1, n = nums.size();
        for(int num : nums)
        {
            int len = 1;
            if(s.find(num-1) == s.end())
            {
                int seq = num;
                while(s.find(seq+1) != s.end()) {
                    seq++;
                    len++;
                }
            }
            maxlen = max(len, maxlen);
        }
        return maxlen;
    }
};