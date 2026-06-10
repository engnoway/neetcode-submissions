class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        int len=0;
        int cnt=0;
        std::set<int>myset(nums.begin(),nums.end());
        int prev=*nums.begin()-1;
        for(auto i: myset){
            if(prev==i-1){
                cnt++;
            }else{
                cnt=1;
            }
            prev=i;
            len=std::max(len,cnt);
        }
        return len;
      
    }
};
