// https://leetcode.com/problems/reverse-string/description/

class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        reverseStringHelper(0, n, s);        
    }

    void reverseStringHelper(int i, int n, vector<char>& s)
    {
        if(i >= n/2) return;
        swap(s[i], s[n-i-1]);
        reverseStringHelper(i+1, n, s);
    }
};