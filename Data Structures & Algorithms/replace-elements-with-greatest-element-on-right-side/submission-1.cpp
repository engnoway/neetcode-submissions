class Solution {
public:

    vector<int> replaceElements(vector<int>& arr) {
        
            for(int k{};k<arr.size();k++){
                int maxi=-1;
                for(int i=k+1;i<arr.size();i++){
                    maxi=max(arr[i],maxi);
                }
                arr[k]=maxi;
            }
            return arr;
    }
};