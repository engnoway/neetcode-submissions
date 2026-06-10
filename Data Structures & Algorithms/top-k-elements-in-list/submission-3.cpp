class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> output;
        vector<vector<int>>buckets((nums.size())+1);
        unordered_map<int,int>mp;
        for(auto i:nums){
            mp[i]++;//store frequenecies
        }
        for(auto&[k,v]:mp){
            buckets[v].push_back(k);
        }
        for(int i=buckets.size()-1;i>0;i--){
        for(auto j : buckets[i])
            {
                output.push_back(j);
            }
            if(k==output.size()) return output;

        }
    return output;

    }
};
