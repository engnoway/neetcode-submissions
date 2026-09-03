class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxarea=0;int width=0,height=0;
        int left=0;
        int right=heights.size()-1;
        while(left<right){
            height=min(heights[left],heights[right]);
            width=right-left;
            maxarea=max(maxarea,(height*width));
            if(heights[left]<heights[right])
                left++;
            else 
                right--;

            // for(int j=i+1;j<heights.size();j++){
            //      height=min(heights[i],heights[j]);
            //      width=j-i;
            //      maxarea=max(maxarea,(height*width));
            // }
        }
        return maxarea;
    }
};
