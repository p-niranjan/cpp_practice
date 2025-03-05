//https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, n = nums.size(), r = n-1;
        while(l < r) {
            int mid = (l + r)/2;
            if(nums[mid] < nums[r]) r = mid;
            else l = mid+1;
        }
        return nums[l];
    }
};
