// https://leetcode.com/problems/isomorphic-strings/description/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, int> charIndexMapS, charIndexMapT;
        if(s.length() != t.length()) return false;
        for(int i = 0; i < s.length(); i++) {
            if(charIndexMapS.find(s[i]) == charIndexMapS.end())
                charIndexMapS[s[i]] = i;
            
            if(charIndexMapT.find(t[i]) == charIndexMapT.end())
                charIndexMapT[t[i]] = i;
            
            if(charIndexMapT[t[i]] != charIndexMapS[s[i]])
                return false;
        }
        return true;
    }
};