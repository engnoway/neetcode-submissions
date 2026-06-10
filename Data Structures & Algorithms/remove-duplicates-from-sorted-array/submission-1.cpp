class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int slow=0,fast=0;
        for(fast=0;fast<nums.size();fast++){
            if(fast==0 || nums[fast]!=nums[fast-1])
                nums[slow++]=nums[fast];
        }
        return slow;

        // int j=0;
        // for(int i=1;i<nums.size();i++){
        //     if((nums[i] !=nums[j])){
        //         j++;
        //         nums[j]=nums[i];
        //     }
            
        // }
        // return j+1;
    }
};