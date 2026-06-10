class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        vector<int>myvect;
        for(auto num:nums){
            mp[num]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>myheap;

        for(auto [element,freq]:mp){
           myheap.emplace(freq,element);
           if(myheap.size() > k)
           myheap.pop();
        }
        while(!myheap.empty()){
            myvect.push_back(myheap.top().second);
            myheap.pop();
        }
        return myvect;
    }
};
