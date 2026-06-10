class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res=0,sum=0;
        unordered_map<int,int>mp{{0,1}};//to handle subarray with index 0
        for(auto num : nums){
            sum+=num;
            res +=mp[sum-k];
            mp[sum]++;
        }
        return res;
    }
};