//https://leetcode.com/problems/group-anagrams/description/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(string s : strs) {
            string word = s;
            sort(word.begin(), word.end());
            mp[word].push_back(s);
        }
        vector<vector<string>> out;
        for(auto w : mp) {
            out.push_back(w.second);
        }
        return out;
    }
};
