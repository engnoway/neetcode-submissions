class Solution {
   public:
    void helper(int index, int n, int k, vector<vector<int>>& out, vector<int>& curr) {
        if (curr.size()== k) {
            out.push_back(curr);
            return;
        }
        for (int i = index; i <= n; i++) {
            curr.push_back(i);
            helper(i + 1, n, k, out, curr);
            curr.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> out;
        vector<int> curr;
        helper(1, n, k, out, curr);
        return out;
    }
};