class Solution {
public:
    vector<vector<int>>ans;
vector<int>curr;
void  dfs(int index,vector<int>&nums){
    ans.push_back(curr);
    for(int i=index;i<nums.size();i++){
        curr.push_back(nums[i]);
        dfs(i+1,nums);
        curr.pop_back();
    }
}
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(0,nums);
        return ans;
    }
};
