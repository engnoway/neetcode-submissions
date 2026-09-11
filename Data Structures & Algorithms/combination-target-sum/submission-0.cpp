class Solution {
   public:
    void dfs(int index, vector<int>& nums, vector<int>& curr, vector<vector<int>>& ans, int target,
             int sum) {
        if (target == sum) {
            ans.push_back(curr);
            return;
        }
        if(sum>target)return;
        for (int i = index; i < nums.size(); i++) {
            curr.push_back(nums[i]);
            sum += nums[i];
             dfs(i, nums, curr, ans, target, sum);
            curr.pop_back();
            sum -= nums[i];
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> curr;

        dfs(0, nums, curr, ans, target, 0);
        return ans;
    }
};
