class Solution {
   public:
    int pivotIndex(vector<int>& nums) {
        vector<int> prefix(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); i++) {
            prefix[i + 1] = nums[i] + prefix[i];
        }
        for (int i = 0; i < nums.size(); i++) {
            if((prefix[i])==(prefix[nums.size()]-prefix[i+1])){
                return i;
            }

        }
        return -1;
    }
};