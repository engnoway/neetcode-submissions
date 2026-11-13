class Solution {
   public:
    void helper(vector<bool>& pick, vector<int>& curr, vector<int>& nums, vector<vector<int>>& out) {
        if(curr.size()==nums.size()){
            out.push_back(curr);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (pick[i]) continue;
            pick[i] = true;
            curr.push_back(nums[i]);
            helper(pick, curr, nums, out);
            curr.pop_back();
            pick[i] = false;
        }
    }

    void permutation(int index, vector<int>& curr, vector<vector<int>>& res, vector<int>& nums,vector<bool>&visited){
		
		for (int i = 0; i < nums.size(); i++) {
			if(curr.size()==nums.size()){
				res.push_back(curr);
				return;
			}
			if (visited[i])
				continue;

			curr.push_back(nums[i]);
			visited[i]=true;
			permutation(i,curr, res, nums,visited);
			curr.pop_back();
			visited[i]=false;
		}
    
	}


    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        vector<bool> visited(nums.size(), false);
        permutation(0, curr, ans, nums,visited);
        return ans;
    }
};
