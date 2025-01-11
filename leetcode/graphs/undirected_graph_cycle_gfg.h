// https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

class Solution {
  public:
    using vertex = pair<int, int>;
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int> vis(V, 0);
        for(int i = 0; i < V; i++)
        {
            if(!vis[i]) {
                if(detectCycle(i, vis, adj)) return true;
            }
        }
        return false;
    }
    
    bool detectCycle(int node, vector<int>& vis, vector<vector<int>>& adj)
    {
        queue<vertex> q;
        q.push({node, -1});
        vis[node] = 1;
        while(!q.empty())
        {
            vertex node_pair = q.front();
            q.pop();
            int cur = node_pair.first;
            int prev = node_pair.second;
            
            for(int nbr : adj[cur])
            {
                if(vis[nbr] == 0) {
                    q.push({nbr, cur});
                    vis[nbr] = 1;
                } else if(nbr != prev) {
                    return true;
                }
            }
        }
        return false;
    }
};