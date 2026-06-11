class Solution {
public:

    vector<int> replaceElements(vector<int>& arr) {
        
            // for(int k{};k<arr.size();k++){
            //     int maxi=-1;
            //     for(int i=k+1;i<arr.size();i++){
            //         maxi=max(arr[i],maxi);
            //     }
            //     arr[k]=maxi;
            // }
            // return arr;
                int maxright=-1;

            for(int i=arr.size()-1;i>=0;--i){
                int temp=arr[i];
                arr[i]=maxright;
                maxright=max(temp,maxright);


            }
            return arr;
    }
};