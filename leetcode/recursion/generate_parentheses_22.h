//https://leetcode.com/problems/generate-parentheses/description/

class Solution {
private:
    void helper(int open, int close, string& s, vector<string> &out) {
        if(0 == close && 0 == open) {
            out.push_back(s);
            return;
        }
        if(open == close) {
            string s1 = s + '(';
            helper(open-1, close, s, out);
        } else if(0 == open) {
            string s1 = s + ')';
            helper(open, close-1, s1, out);
        } else if(0 == close) {
            string s1 = s + ')';
            helper(open-1, close, s1, out);
        } else {
            string s1 = s + ')';
            helper(open, close-1, s1, out);
            string s2 = s + '(';
            helper(open-1, close, s2, out);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> out;
        int open = n, close = n;
        string s;
        helper(open, close, s, out);
        return out;        
    }
};
