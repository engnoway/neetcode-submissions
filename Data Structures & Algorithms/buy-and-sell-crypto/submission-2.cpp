class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        // for (int i = 0; i < prices.size(); i++) {
        //     for (int j = i + 1; j < prices.size(); j++) {
        //         diff = prices[j] - prices[i];
        //         maxprof = max(maxprof, diff);
        //     }
        // }
        int maxprof = 0;

        int left = 0, right = 1, diff = 0;
        while (right < prices.size()) {
            
            if (prices[right] < prices[left]) {
                left = right;
            } else {
                maxprof = max(maxprof, prices[right]-prices[left]);
            }
            right++;
        }
        return maxprof;
    }
};
