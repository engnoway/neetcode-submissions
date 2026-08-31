class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        vector<int>res(nums.size());
        int prefix=1;
        for(int i=0;i<nums.size();i++){
            res[i]=prefix;
            prefix *=nums[i];
        }
        int suffix=1;
        for(int j=nums.size()-1;j>=0;j--){
            res[j] *=suffix;
            suffix *=nums[j];
        }
        return res;
    }
};
