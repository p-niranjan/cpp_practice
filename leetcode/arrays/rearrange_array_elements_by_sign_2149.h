// https://leetcode.com/problems/rearrange-array-elements-by-sign/
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size(), posIdx = 0, negIdx = 1;
        vector<int> out(n);
        for(int num : nums)
        {
            if(num < 0) {
                out[negIdx] = num;
                negIdx += 2;
            } else {
                out[posIdx] = num;
                posIdx += 2;
            }
        }
        return out;
    }
};

# Convert the input string to lowercase, replace spaces with underscores, and append .h
filename=$(echo "$1" | tr '[:upper:]' '[:lower:]' | sed 's/ /_/g')_.h

# Create the file in the current directory
touch "$filename"

# Notify the user
echo "File '$filename' created successfully."