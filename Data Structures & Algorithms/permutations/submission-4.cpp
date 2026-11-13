class Solution {
   public:
    void permutation(int index, vector<int>& curr, vector<vector<int>>& res, vector<int>& nums,
                     vector<bool>& visited) {
        if (curr.size() == nums.size()) {
            res.push_back(curr);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (visited[i]) continue;

            curr.push_back(nums[i]);
            visited[i] = true;
            permutation(i, curr, res, nums, visited);
            curr.pop_back();
            visited[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        vector<bool> visited(nums.size(), false);
        permutation(0, curr, ans, nums, visited);
        return ans;
    }
};
