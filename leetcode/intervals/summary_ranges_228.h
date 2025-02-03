// https://leetcode.com/problems/summary-ranges/description/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        if(0 == nums.size()) return {};        
        vector<string> out;
        for(int i = 0; i < n; i++)
        {
            int begin = nums[i];
            while(i + 1 < n && nums[i] == nums[i+1]-1) i++;
            int end = nums[i];
            if(begin == end) out.push_back(to_string(begin));
            else out.push_back(to_string(begin) + "->" + to_string(end));
        }
        return out;
    }
};