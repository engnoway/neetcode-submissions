class Solution {
public:
    int trap(vector<int>& height) {
        int left=0;
        int right=height.size()-1;
        int maxleft=height[0];
        int maxright=height[right];
        int res=0;

        while(left<right){
            if(maxleft<maxright){
                left++;
                maxleft=max(maxleft,height[left]);
                 res += maxleft-height[left];
            }else{
                right--;
                maxright=max(maxright,height[right]);
                res += maxright-height[right];
            }
           
        }
        return res;
    }
};
