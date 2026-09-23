class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        // int sum = 0, ans = INT_MIN;
        // for (int i = 0; i < nums.size(); i++) {
        //     sum += nums[i];
        //     ans = max(ans, sum);
        //     if (sum < 0) sum = 0;
        // }
        // return ans;
        int maxsum=nums[0];
        // for(int i=0;i<nums.size();i++){
        //     int currsum=0;
        //     for(int j=i;j<nums.size();j++){
        //          currsum += nums[j];
        //         maxsum=max(maxsum,currsum);
        //     }
        // }
        //kadane algo
        int currsum=0;
                for(int i=0;i<nums.size();i++){
                    currsum=max(currsum,0);
                    currsum+=nums[i];
                     maxsum=max(maxsum,currsum);
                }

        return maxsum;
    }
};
