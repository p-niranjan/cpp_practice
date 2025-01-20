// https://leetcode.com/problems/ransom-note/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mg;
        for(char m : magazine) mg[m]++;

        for(char r : ransomNote) {
            if(mg.find(r) != mg.end()) {
                mg[r]--;
                if(mg[r] == 0) mg.erase(r);
            } else {
                return false;
            }
        }
        return true;
    }
};