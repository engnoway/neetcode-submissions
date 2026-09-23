class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        for(int L=0;L<nums.size();L++){
            //int len=min(static_cast<int>(nums.size()),L+k);
            for(int R=L+1;R<nums.size();R++){
                if((nums[R]==nums[L])&&((R-L)<=k)) return true;
            }
        }
        return false;
    }
};