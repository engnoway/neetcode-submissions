class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxsum=nums[0];
       int currsum=0;

       int minsum=nums[0];
       int currmin=0;
       int totalsum=0;
        for(int i=0;i<nums.size();i++){
            
            currsum=max(currsum+nums[i],nums[i]);
            maxsum=max(maxsum,currsum);

            currmin=min(currmin+nums[i],nums[i]);
            minsum=min(currmin,minsum);
            totalsum+=nums[i];
        }
        if(maxsum<0)return maxsum;
        return max(maxsum,totalsum-minsum);
    }
};