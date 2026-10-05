class Solution {
   public:
    void helper(int index, vector<int>& nums, vector<vector<int>>& out, vector<int>& currspset) {
        out.push_back(currspset);
        for (int i = index; i < nums.size(); i++) {
            if (i > index && nums[i] == nums[i - 1]) continue;
            currspset.push_back(nums[i]);
            helper(i + 1, nums, out, currspset);
            currspset.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> out;
        vector<int> currspset;
        sort(nums.begin(), nums.end());

        helper(0, nums, out, currspset);
        return out;
    }
};
