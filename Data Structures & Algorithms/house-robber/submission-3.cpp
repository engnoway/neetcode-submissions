class Solution {
   public:
    // vector<int> memo;

    // int dfs(vector<int>& nums, int i) {
    //     if (i >= nums.size()) return 0;
    //     if (memo[i] != -1) return memo[i];

    //     int rob = nums[i] + dfs(nums, i + 2);
    //     int skip = dfs(nums, i + 1);
    //     memo[i] = max(rob, skip);
    //     return memo[i];
    // }
    int rob(vector<int>& nums) {
        // memo.resize(nums.size(), -1);
        // return dfs(nums, 0);

        int n = nums.size();
        if (n == 1) return nums[0];

        int prev2 = nums[0];                // dp[i-2]
        int prev1 = max(nums[0], nums[1]);  // dp[i-1]
        int rob=0,skip=0,curr=0;
        for (int i = 2; i < nums.size(); i++) {
             rob = prev2 + nums[i];
             skip = prev1;
             curr = max(skip, rob);
                    prev2 = prev1;
        prev1 = curr;
        }
 
        return prev1;
        // vector<int>dp(n);
        // dp[0]=nums[0];
        // dp[1]=max(nums[0],nums[1]);
        // for(int i=2;i<nums.size();i++){
        //     dp[i]=max(nums[i]+dp[i-2],dp[i-1]);
        // }
        // return dp[n-1];
    }
};
