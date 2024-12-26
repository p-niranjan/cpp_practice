// https://leetcode.com/problems/valid-palindrome/description/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    bool isAlphaNumeric(const char ch)
    {
        return (ch >= 'a' && ch  <= 'z') || (ch >= '0' && ch <= '9');
    }

    bool isPalindrome(string s) {
        string clean;
        for(char c : s)
        {
            char lower = tolower(c);
            if(isAlphaNumeric(lower)) clean += lower;
        }
        string rev = clean;
        reverse(rev.begin(), rev.end());
        return rev == clean;
    }
};