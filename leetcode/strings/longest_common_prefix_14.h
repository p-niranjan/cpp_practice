// https://leetcode.com/problems/longest-common-prefix/description/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();        
        sort(strs.begin(), strs.end());
        
        string first = strs[0], last = strs[n-1], out{};
        int i = 0, j = 0;
        while(i < first.length() && j < last.length()) {
            if(first[i] != last[j]) break;
            out += first[i];
            i++;
            j++;
        }
        return out;
    }
};