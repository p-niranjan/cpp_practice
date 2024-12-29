// https://www.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1

class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        unordered_map<char, int> mp;
        int l = 0, r = 0, n = s.length();
        int len = INT_MIN;
        while(r < n)
        {
            mp[s[r]]++;
            while(mp.size() > k) {
                mp[s[l]]--;
                if(0 == mp[s[l]]) mp.erase(s[l]);
                l++;
            }
            if(k == mp.size()) {
                len = max(len, r - l + 1);
            }
            r++;
        }
        return (INT_MIN == len) ? -1 : len;
    }
};