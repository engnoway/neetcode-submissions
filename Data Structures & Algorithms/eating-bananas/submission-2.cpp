class Solution {
   public:
    // bool canfinish(vector<int>& piles, int h, int k) {
    //     long long hours = 0;
    //     for (auto p : piles) {
    //         hours += (p + k - 1) / k;
    //     }
    //     return hours <= h;
    // }
    int minEatingSpeed(vector<int>& piles, int h) {
        // int left=1;
        // int right= *max_element(piles.begin(),piles.end());
        // int ans=right;

        // while(left<=right){
        //     int mid=left+(right-left)/2;
        //     if(canfinish(piles,h,mid)){
        //         ans=mid;
        //         right=mid-1;
        //     }else{
        //         left=mid+1;
        //     }
        // }
        // return ans;

        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        int ans = right;
       
        while (left <= right) {
             long int tot = 0;
            int k = left + (right - left) / 2;
            for (auto p : piles) {
                tot += (p + (k - 1)) / k;
            }
            if (tot <= h) {  // slow down
                ans = k;
                right = k - 1;
            } else {  // increase the speed k
                left = k + 1;
            }
        }
        return ans;
    }
};
