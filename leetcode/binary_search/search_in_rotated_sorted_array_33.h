//https://leetcode.com/problems/search-in-rotated-sorted-array/description/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        while(low <= high) {
            int mid = (low + high)/2;
            if(nums[mid] == target) return mid;
            // if left half is sorted
            if(nums[low] <= nums[mid]) {
                if(target >= nums[low] && target < nums[mid]) 
                    high = mid-1;
                else 
                    low = mid+1;
            } else {
                if(target > nums[mid] && target <= nums[high]) 
                    low = mid+1;
                else 
                    high = mid-1;
            }
        }
        return -1;
    }
};
