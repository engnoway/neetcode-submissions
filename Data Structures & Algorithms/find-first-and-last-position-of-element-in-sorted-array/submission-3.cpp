class Solution {
   public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = -1, last = -1;
        int left = 0, right = nums.size() - 1;
        // for (int i = 0; i < nums.size(); i++) {
        //     if (target == nums[i]) {
        //         if(first==-1)
        //             first=i;
        //         last=i;

        //     }
        // }
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                first = mid;
                right = mid - 1;
            }
            if (nums[mid] > target) right = mid - 1;
            if (nums[mid] < target) left = mid + 1;
        }
         left = 0;
          right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                last = mid;
                left = mid + 1;
            }
            if (nums[mid] > target) right = mid - 1;
            if (nums[mid] < target) left = mid + 1;
        }
        return {first, last};
    }
};