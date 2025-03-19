//https://leetcode.com/problems/keys-and-rooms/description/

class Solution {
public:
    void dfs(unordered_set<int>& vis, int idx, vector<vector<int>>& rooms) {
        vis.insert(idx);

        if(rooms[idx].size() == 0) return; 

        for(auto adj : rooms[idx]) {
            if(vis.find(adj) == vis.end()) {
                dfs(vis, adj, rooms);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        unordered_set<int> vis;
        dfs(vis, 0, rooms);
        return vis.size() == rooms.size();
    }
}; 
