// https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<vector<int>> adjL) {
        vector<int> indegree(V, 0);
        for(int v = 0; v < V; v++)
        {
            for(int w : adjL[v]) indegree[w]++;
        }
        
        queue<int> q;
        for(int v = 0; v < V; v++) {
            if(0 == indegree[v]) q.push(v);
        }
        
        vector<int> topo;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(int adj : adjL[node])
            {
                indegree[adj]--;
                if(0 == indegree[adj]) q.push(adj);
            }
        }
        return topo.size() != V;
    }
};
