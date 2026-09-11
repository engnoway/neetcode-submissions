class Solution {
   public:
    void dfs(vector<bool>& pick, vector<int>& curr, vector<int>& nums, vector<vector<int>>& ans) {
        if (curr.size() == nums.size()) {
            ans.push_back(curr);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!pick[i]) {
                curr.push_back(nums[i]);
                pick[i] = true;
                dfs(pick, curr, nums, ans);
                curr.pop_back();
                pick[i] = false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        vector<bool> pick(nums.size(),false);
        dfs(pick, curr, nums, ans);
        return ans;
    }
};
