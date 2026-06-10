class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int len=0,maxlen=0;
        unordered_set<int>myset(nums.begin(),nums.end());
        for(int num : myset){
            if(!myset.count(num-1)){
                int curr=num;
                len=1;
                while(myset.count(curr+1)){
                    len++;
                    curr++;
                }
            }
            maxlen=max(maxlen,len);

        }
        return maxlen;
    }
};
