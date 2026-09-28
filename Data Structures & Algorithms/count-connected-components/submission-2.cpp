class Solution {
   public:
    int find(int x, vector<int>& par) {
        if (x == par[x]) return x;
        return par[x] = find(par[x], par);
    }

    void unionset(vector<int>& par, vector<int>& sizes, int a, int b) {
        if (sizes[a] < sizes[b]) {
            par[a] = b;
            sizes[b] += sizes[a];
        } else {
            par[b] = a;
            sizes[a] += sizes[b];
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> par(n, 0);
        vector<int> sizes(n, 1);
        int component = n;
        for (int i = 0; i < n; i++) par[i] = i;

        for (auto edg : edges) {
            int a = edg[0];
            int b = edg[1];
            int roota = find(a, par);
            int rootb = find(b, par);
            if (roota != rootb){//connect them
            unionset(par, sizes, roota, rootb);
component--;
            } 
            // par[roota] = rootb;
        }
        return component;
    }
};
