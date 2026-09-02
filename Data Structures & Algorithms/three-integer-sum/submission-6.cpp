class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int r = 0, l = 0;
        vector<vector<int>> out;
        int j = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            l = i + 1;
            r = nums.size() - 1;
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];

                if (sum < 0) {
                    l++;
                } else if (sum > 0) {
                    r--;
                } else {
                    out.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                    while (l < r && nums[l] == nums[l - 1]) l++;
                    while (l < r && nums[r] == nums[r + 1]) r--;
                }
            }
        }
        return out;
    }
};
