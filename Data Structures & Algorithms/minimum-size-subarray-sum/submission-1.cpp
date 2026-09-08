class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // int left=0,right=0,sum=0;
        // int minlen=INT_MAX;
        // while(right<nums.size()){
        //     sum+=nums[right];
        //     while(sum>=target){
        //         minlen=min(minlen,right-left+1);
        //     sum-=nums[left]; 
        //     left++;
        //     }
        //     right++;

        // }
        // return minlen==INT_MAX ? 0:minlen;

int sum=0;int mini=INT_MAX,len=0;
        for(int i=0;i<nums.size();i++){
            sum=0;
            len=0;
            for(int j=i;j<nums.size();j++){
                sum+=nums[j];
                    len++;
                if(sum>=target){
                    mini=min(mini,len);
                    break;
                }
            }
        }
        return mini==INT_MAX?0:mini;
    }
};