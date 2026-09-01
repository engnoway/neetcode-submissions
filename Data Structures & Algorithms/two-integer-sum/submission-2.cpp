class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            int res=target-nums[i];
            if(mp.count(res)){
                return{mp[res],i};
            }
            mp[nums[i]]=i;
        }
        return{};
    //     for(int i=0;i<nums.size();i++){
    //         for(int j=i+1;j<nums.size();j++){
    //             if(target==(nums[i]+nums[j])){
    //                 return {i,j};
    //             }
    //         }
    //     }
    //     return {};
    // }
    }
};
