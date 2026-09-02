class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // int left=0;
        // int right=numbers.size()-1;
        // while(left<right){
        //     int sum= numbers[left]+numbers[right];
        //     if(sum==target) return{left+1,right+1};

        //     if(sum<target){
        //         left++;
        //     }else{
        //         right--;
        //     }
        // }
        // return {};
        unordered_map<int,int>mp;
        for(int i=0;i<numbers.size();i++){
            int num=target-numbers[i];
            if(mp.count(num)){
                    return {mp[num],i+1};
            }
            mp[numbers[i]]=i+1;
        }
    }
};
