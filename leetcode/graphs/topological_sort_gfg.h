// https://www.geeksforgeeks.org/problems/topological-sort/1

class Solution {
  public:
    // Function to return list containing vertices in Topological order.
    vector<int> topologicalSort(vector<vector<int>>& adjL) {
        const int V = adjL.size();
        vector<int> indegree(V, 0);
        for(int v = 0; v < V; v++)
        {
            for(int adj : adjL[v]) indegree[adj]++;
        }
        
        queue<int> q;
        for(int i = 0; i < V; i++) 
        {
            if(0 == indegree[i]) q.push(i);
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
        return topo;
    }
};