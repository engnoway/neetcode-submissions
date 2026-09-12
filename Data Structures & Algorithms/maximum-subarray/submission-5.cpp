class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // int maxi=INT_MIN;
        // int cursum=0;
        //     int l = 0;
        //     int r = l+1;

        // for( l=0;l<nums.size();l++){
        //     cursum +=nums[l];
        //     maxi=max(cursum,maxi);
        //     if(cursum<0){
        //         cursum=0;
        //     }
        // }
        // return maxi;
int sum=0,ans=INT_MIN;
for(int i=0;i<nums.size();i++){
    if(nums.size()==1) return nums[i];
    sum+=nums[i];
    ans=max(ans,sum);
    if(sum<0) sum=0;
}
return ans;
}


        
    
};
