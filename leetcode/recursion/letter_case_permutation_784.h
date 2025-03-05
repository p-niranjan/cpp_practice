//https://leetcode.com/problems/letter-case-permutation/description/

class Solution {
    void helper(int idx, string& s, vector<string> &out) {
        const int n = s.length();
        if(n == idx) {
            out.push_back(s);
            return;
        }
        if(isalpha(s[idx])) {
            helper(idx+1, s, out);
            s[idx] = isupper(s[idx]) ? tolower(s[idx]) : toupper(s[idx]);
            helper(idx+1, s, out);
        } else {
            helper(idx+1, s, out);
        }
    }
public:
    vector<string> letterCasePermutation(string s) {
        if(s.empty()) return {};

        vector<string> out;
        helper(0, s, out);
        return out;
    }
};
