class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeros = 0, ones = 0, twos = 0;
        for(int num : nums)
        {
            if(0 == num) zeros++;
            else if(1 == num) ones++;
            else twos++;
        }

        int idx = 0;
        for(int i = 0; i < zeros; i++) nums[idx++] = 0;
        for(int i = 0; i < ones; i++) nums[idx++] = 1;
        for(int i = 0; i < twos; i++) nums[idx++] = 2;  
    }
};