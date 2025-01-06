// https://leetcode.com/problems/number-of-provinces/description/

class Solution {
public:
    void dfs(int idx, vector<int>& vis, vector<vector<int>>& adjL)
    {
        vis[idx] = 1;
        for(int adj : adjL[idx])
        {
            if(vis[adj] == 0) {
                dfs(adj, vis, adjL);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adjL(n);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++) {
                if(isConnected[i][j]) {
                    adjL[i].push_back(j);
                    adjL[j].push_back(i);
                }
            }
        }

        vector<int> vis(n, 0);
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            if(vis[i] == 0) {
                cnt++;
                dfs(i, vis, adjL);                
            }
        }
        return cnt;
    }
};