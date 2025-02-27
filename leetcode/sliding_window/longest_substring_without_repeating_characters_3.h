//https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLength = 0, n = s.length();
        int r = 0, l = 0;
        unordered_map<char, int> mp;
        while(r < n) {
            char right = s[r];
            if(mp.find(right) == mp.end() || mp[right] < l) {
                maxLength = max(maxLength, r - l + 1);               
            } else {
                l = mp[right]+1;                              
            }
            mp[right] = r;
            r++;
        }
        return maxLength;
    }
};
