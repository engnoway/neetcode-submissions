class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sum=0,maxlen=0;
        unordered_map<int,int>mp{{0,-1}};
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                sum--;
            }else{
                sum++;
            }
            if(mp.count(sum)){
                maxlen=max(maxlen,i-mp[sum]);
            }else{
                mp[sum]=i;
            }
        }
        return maxlen;
    }
};
