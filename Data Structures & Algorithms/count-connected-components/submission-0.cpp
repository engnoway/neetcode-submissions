class Solution {
   public:
    int find(int x, vector<int>& par) {
        if (x == par[x]) return x;
        return par[x] = find(par[x], par);
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> par(n, 0);
        int component=n;
        for (int i = 0; i < n; i++) par[i] = i;

        for (auto edg : edges) {
            int a = edg[0];
            int b = edg[1];
            int roota = find(a, par);
            int rootb = find(b, par);
            if (roota != rootb) component--;
            par[roota] = rootb;
        }
        return component;
    }
};
