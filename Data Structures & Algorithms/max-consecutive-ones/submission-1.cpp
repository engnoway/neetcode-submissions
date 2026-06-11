class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt=0;
        int maxi=0;
        for(size_t i{0};i<nums.size();i++){
            cnt = nums[i]==1 ? cnt+1:0;
            maxi=max(cnt,maxi);
        }
        return maxi;
    }
};