class MedianFinder {
   public:
    // vector<int>nums;
    priority_queue<int> small;
    priority_queue<int, vector<int>, greater<int>> large;
    MedianFinder() {}

    void addNum(int num) {
        // nums.push_back(num);
        // know which half we will insert
        if (small.empty() || num <= small.top()) {
            small.push(num);
        } else {
            large.push(num);
        }
        // do balance
        if (small.size() > large.size() + 1) {
            large.push(small.top());
            small.pop();
        } else if (large.size() > small.size() + 1) {
            small.push(large.top());
            large.pop();
        }
    }

    double findMedian() {
        // sort(nums.begin(),nums.end());
        // int n=nums.size();
        // if(n==0) return 0.0;
        // if(n%2==1) return nums[n/2];
        // else{
        //     return (nums[n/2]+nums[n/2-1])/2.0;
        // }
        if(small.size()==large.size()){
            return (small.top()+large.top())/2.0;
        }
        if(small.size()>large.size()){
            return small.top();
        }else{
            return large.top();
        }
    }
};
