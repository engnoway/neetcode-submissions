class Solution {
   public:
    void dfs(int index, vector<int>& nums, vector<int>& curr, vector<vector<int>>& ans) {
        ans.push_back(curr);
        for (int i = index; i < nums.size(); i++) {
            curr.push_back(nums[i]);
            dfs(i + 1, nums,curr,ans);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;

        dfs(0, nums,curr,ans);
        return ans;
    }
};
