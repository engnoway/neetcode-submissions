class Solution {
   public:
    int find(vector<int>& par, int x) {
        if (x == par[x]) return x;
       //return find(par, par[x]);
       return par[x]=find(par,par[x]);//path compression i.e get the root from find then make the node refre to it directly 
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> parent(edges.size() + 1, 0);
        for (int i = 1; i < parent.size(); i++) {
            parent[i] = i;
        }
        for (const auto& ed : edges) {
            int a = ed[0];
            int b = ed[1];

            int rootA = find(parent, a);
            int rootB = find(parent, b);
            if (rootA == rootB)  // cycle here
                return {a, b};
            parent[rootB] = rootA;//union or combine 
        }
    }
};
