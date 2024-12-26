// https://leetcode.com/problems/remove-duplicates-from-sorted-array/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        int i = 0;
        for(auto num : s) nums[i++] = num;        
        return s.size();
    }
};

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j = 1, n = nums.size();
        for(int i = 1; i < n; i++)
        {
            if(nums[i] != nums[j-1])
            {
                nums[j++] = nums[i];
            }

        }
        return j;
    }
};