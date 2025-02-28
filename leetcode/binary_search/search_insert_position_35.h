//https://leetcode.com/problems/search-insert-position/description/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start = 0, end = nums.size()-1;
        while(start <= end) {
            int mid = (start + end)/2;
            if(nums[mid] == target) return mid;
            if(nums[mid] > target) end = mid-1;
            else start = mid+1;
        }
        return start;
    }
};
