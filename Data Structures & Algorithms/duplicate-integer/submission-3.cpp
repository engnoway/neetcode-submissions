class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        //braut force
        // for(int i=0;i<nums.size();i++){
        //     int temp=nums[i];
        //     for(int j=i+1;j<nums.size();j++){
        //         if(temp==nums[j])return true;
        //     }
        // }
        // return false;
        // unordered_map<int,int>mp;
        // for(auto element:nums){
        //     mp[element]++;
        // }
        // for(auto it:mp){
        //     if(it.second > 1)
        //     return true;
        // }
        // return false;

        unordered_set<int>myset;
        for(auto element :nums){
            if(myset.count(element))
            return true;
            myset.insert(element);
        }
        return false;
    }
};