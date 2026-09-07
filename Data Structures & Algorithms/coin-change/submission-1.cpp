class Solution {
   public:
    vector<int> mem;
    int dfs(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        if (amount < 0) return INT_MAX;
        int mini = INT_MAX;
        if (mem[amount] != -1) return mem[amount];

        for (auto coin : coins) {
            int result = dfs(coins, amount - coin);
            if (result != INT_MAX) {
                mini = min(mini, 1 + result);
            }
        }
        mem[amount] = mini;

        return mem[amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        mem.resize(amount + 1, -1);
        int ans = dfs(coins, amount);
        if (ans == INT_MAX) return -1;
        return ans;
    }
};
