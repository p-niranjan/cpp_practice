// https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size(), maxi = arr[n-1];
        vector<int> out(n, -1);
        out[n-1] = -1;
        for(int i = n-2; i >= 0; i--)
        {
            maxi = max(maxi, arr[i+1]);
            out[i] = maxi;
        }
        return out;
    }
};