class Solution {
   public:
    int subarraySum(vector<int>& nums, int k) {
        // int res=0,sum=0;
        // unordered_map<int,int>mp{{0,1}};//to handle subarray with index 0
        // for(auto num : nums){
        //     sum+=num;
        //     res +=mp[sum-k];
        //     mp[sum]++;
        // }
        // return res;
        int cnt = 0;
        for (int start = 0; start < nums.size(); start++) {
            int sum = 0;
            for (int end = start; end < nums.size(); end++) {
                sum += nums[end];
                if (sum == k) {
                    cnt++;  // number of subarrays
                }
            }
        }
        return cnt;
    }
};