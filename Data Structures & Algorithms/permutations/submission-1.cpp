class Solution {
   public:
    void helper(vector<bool> pick, vector<int>& curr, vector<int>& nums, vector<vector<int>>& out) {
        if(curr.size()==nums.size()){
            out.push_back(curr);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (pick[i]) continue;
            pick[i] = true;
            curr.push_back(nums[i]);
            helper(pick, curr, nums, out);
            curr.pop_back();
            pick[i] = false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        vector<bool> pick(nums.size(), false);
        helper(pick, curr, nums, ans);
        return ans;
    }
};
