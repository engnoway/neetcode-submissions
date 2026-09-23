class Solution {
   public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        for(int L=0;L<nums.size();L++){
            int len=min(static_cast<int>(nums.size()),L+k+1);
            for(int R=L+1;R<len;R++){
                if((nums[R]==nums[L])) return true;
            }
        }
        return false;

        // int L = 0;
        // unordered_set<int> myset;
        // for (int R = 0; R < nums.size(); R++) {
        //     if (R - L > k) {
        //         myset.erase(nums[L]);
        //         L++;
        //     }
        //     if (myset.count(nums[R])) {
        //         return true;
        //     }
        //     myset.insert(nums[R]);
        // }
        // return false;
    }
};