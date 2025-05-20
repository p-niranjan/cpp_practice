//https://leetcode.com/problems/gas-station/description/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    int strStr(string haystack, string needle) {
        const int m = haystack.size(), n =  needle.size();
        for(int i = 0; i <= m-n; i++) {
            if(haystack.substr(i, n) == needle)
                return i;
        }
        return -1;
    }
};
