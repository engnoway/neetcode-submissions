class Solution {
   public:
    void helper(int index, vector<int>& nums, vector<int>& curr, vector<vector<int>>& out, int sum,
                int target) {
        if (sum == target) {
            out.push_back(curr);
            return;
        }
        if (sum > target) return;
        for (int i = index; i < nums.size(); i++) {
            curr.push_back(nums[i]);
            helper(i, nums, curr, out, sum+nums[i], target);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        helper(0, nums, curr, ans, 0, target);

        return ans;
    }
};
