class Solution {
   public:
    bool dfs(vector<vector<int>>& adj, vector<bool>& vis, int node, int parent) {
        vis[node] = true;  // mark the node is visited
        for (auto n : adj[node]) {
            if (n == parent) continue;
            if (vis[n] == true) return true;
            if( dfs(adj, vis, n, node)) return true;
        }
        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> vis(n, false);

        for (auto e : edges) {
            int a = e[0];
            int b = e[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        if (dfs(adj, vis, 0, -1)) return false;
        for(auto i:vis){
            if(!i) return false;
        }
        return true;
    }
};
