class Solution {
   public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for (auto i : nums) {
            pq.push(i);
        }
        while (k >=0 ) {
            
            if (k == 1) {
                return pq.top();
            }
            pq.pop();
            k--;
        }
        return -1;
    }
};
