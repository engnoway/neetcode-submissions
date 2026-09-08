class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> out;
        deque<int> dq;
       // int maxi = 0;
        // for(int i=0;i<=(nums.size()-k);i++){
        //     maxi=nums[i];
        //     for(int j=i;j<k+i;j++){
        //         maxi=max(maxi,nums[j]);
        //     }
        //     out.push_back(maxi);
        // }
        int right = 0;
        while (right < nums.size()) {
//remove smaller elements from the dequee
            while (!dq.empty() && nums[right] >= nums[dq.back()]) {
                dq.pop_back(); 
            }
            dq.push_back(right);

            if (!dq.empty() && dq.front() < right - k + 1) { //remove this elements as its index got out from the curr window
                dq.pop_front();
            }
            if(right>=k-1)//complete window so push the front of dequeue into the vector
            out.push_back(nums[dq.front()]);

            right++;
        }
        return out;
    }
};
