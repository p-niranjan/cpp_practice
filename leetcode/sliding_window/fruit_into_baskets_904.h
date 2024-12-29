// https://leetcode.com/problems/fruit-into-baskets/

class Solution {
public: 
    int totalFruit(vector<int>& fruits) {
        int l = 0, r = 0, n = fruits.size();
        int cnt = 0, len = -1e9;
        unordered_map<int, int> mp;
        while(r < n)
        {
            mp[fruits[r]]++;
            while(mp.size() > 2) {
                mp[fruits[l]]--;
                if(mp[fruits[l]] == 0) mp.erase(fruits[l]);
                l++;
            }
            if(mp.size() <= 2) len = max(len, r-l+1);
            r++;
        }
        return len;
    }   
};