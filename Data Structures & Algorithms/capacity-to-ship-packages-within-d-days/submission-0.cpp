class Solution {
   public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end());    // min weight
        int right = accumulate(weights.begin(), weights.end(), 0);  // max weight
        int ans = left;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int totdays =1;
            int currweight=0;
            for (auto& w : weights) {
                if(currweight+w >mid){
                    currweight=0;
                    totdays++;
                }
                currweight+=w;
            }
            if (totdays <= days) {
                right = mid - 1;
                ans = mid;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};