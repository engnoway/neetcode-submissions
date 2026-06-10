class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi=INT_MIN;
        int cursum=0;
            int l = 0;
            int r = l+1;

        for( l=0;l<nums.size();l++){
            cursum +=nums[l];
            maxi=max(cursum,maxi);
            if(cursum<0){
                cursum=0;
            }
        }
        return maxi;
    }
};
