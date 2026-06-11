class Solution {
public:
int findmax(int start,vector<int>& arr){
int maxelement=arr[start];
    for(int i{start};i<arr.size();i++){
        if(arr[i]> maxelement)
        maxelement=arr[i];
    }
    return maxelement;
}
    vector<int> replaceElements(vector<int>& arr) {
        int j=1;
            for(int k{};k<arr.size()-1;k++){
                arr[k]=findmax(j,arr);
                j++;
            }
            arr[arr.size()-1]=-1;
            return arr;
    }
};