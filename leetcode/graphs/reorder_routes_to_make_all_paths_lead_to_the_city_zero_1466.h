// https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/description/?envType=study-plan-v2&envId=leetcode-75

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>> adjL(n);
        for(auto connection : connections) {
            adjL[connection[0]].push_back({connection[1], 1});
            adjL[connection[1]].push_back({connection[0],-1});
        }
        vector<int> vis(n, 0);
        int minEdges = 0;
        dfs(0, adjL, vis, minEdges);
        return minEdges;
    }

    void dfs(int idx, vector<vector<pair<int,int>>> &adjL, vector<int> &vis, int &minEdges)
    {
        vis[idx] = 1;
        for(auto p : adjL[idx])
        {
            int city = p.first;
            int dir = p.second;            
            if(vis[city] == 0) {
                if(dir == 1) minEdges++;
                dfs(city, adjL, vis, minEdges);
            }
        }
    }
};