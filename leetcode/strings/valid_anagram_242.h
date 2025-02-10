// https://leetcode.com/problems/valid-anagram/description/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;

        unordered_map<char, int> smap, tmap;
        for(char c : s) smap[c]++;
        for(char c : t) tmap[c]++;

        for(char c : s)
            if(tmap[c] != smap[c]) return false;

        return true;
    }
};