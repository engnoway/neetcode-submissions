class NumArray {
public:
vector<int>prefx;
    NumArray(vector<int>& nums) {
        prefx=vector<int>(nums.size()+1,0);
        for(int i=0;i<nums.size();i++){
            prefx[i+1]=prefx[i]+nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        int sum=prefx[right+1]-prefx[left];
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */