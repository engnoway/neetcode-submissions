class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //     vector<int> output;
        //     vector<vector<int>>buckets((nums.size())+1);
        //     unordered_map<int,int>mp;
        //     for(auto i:nums){
        //         mp[i]++;//store frequenecies
        //     }
        //     for(auto&[k,v]:mp){
        //         buckets[v].push_back(k);
        //     }
        //     for(int i=buckets.size()-1;i>0;i--){
        //     for(auto j : buckets[i])
        //         {
        //             output.push_back(j);
        //         }
        //         if(k==output.size()) return output;

        //     }
        // return output;
        unordered_map<int,int>mp;
        vector<int> output;
        priority_queue<pair<int,int>> pq;
        for (auto num:nums) {
           mp[num]++;
        }
        for(auto[key,val]:mp){
            pq.emplace(val,key);
        }
        while(!pq.empty()  && k>=1){
            output.emplace_back(pq.top().second);
            pq.pop();
            k--;
        }
        return output;
    }
};
