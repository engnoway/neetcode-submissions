class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxarea=0;int width=0,height=0;
        int left=0;
        int right=heights.size()-1;
        while(left<right){
           maxarea=max(maxarea,(right-left)*min(heights[left],heights[right]));
           if(heights[left]<heights[right])left++;
           else right--;
        }
        return maxarea;
    }
};
