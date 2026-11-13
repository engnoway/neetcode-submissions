class Solution {
   public:
    // void dfs(int index, vector<int>& nums, vector<int>& curr, vector<vector<int>>& ans) {
    //     ans.push_back(curr);
    //     for (int i = index; i < nums.size(); i++) {
    //         curr.push_back(nums[i]);
    //         dfs(i + 1, nums,curr,ans);
    //         curr.pop_back();
    //     }
    // }

    void backtrack(int index, vector<int>& curr, vector<vector<int>>& res, vector<int>& nums) {
        if (index == nums.size()) {
            res.push_back(curr);
            return;
        }
        // choose num[index]
        curr.push_back(nums[index]);
        backtrack(index + 1, curr, res, nums);
        curr.pop_back();
        // un choose num[index]

        backtrack(index + 1, curr, res, nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        // vector<vector<int>> ans;
        // vector<int> curr;

        // dfs(0, nums,curr,ans);
        // return ans;
        vector<int> current;
        vector<vector<int>> res;
        backtrack(0, current, res, nums);
        return res;
    }
};
