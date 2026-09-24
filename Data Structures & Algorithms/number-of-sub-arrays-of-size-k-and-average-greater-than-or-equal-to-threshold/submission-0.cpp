class Solution {
   public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int L = 0;
        int sum = 0, len = 0;
        for (int R = 0; R < arr.size(); R++) {
                        sum += arr[R];

            if ((R - L > k-1) ) {
               
                sum -= arr[L];
                 L++;
            }
   
            if ((R - L) == k-1) { //window width is k
                if((sum/k)>=threshold)len++;
            }
        }
        return len;
    }
};