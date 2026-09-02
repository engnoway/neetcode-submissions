class Solution {
public:
    bool isPalindrome(string s) {
        string copy;
        for(auto ch:s){
            if(isalnum(static_cast<unsigned char>(ch)))
                copy+=tolower(static_cast<unsigned char>(ch));
        }
        int j=  copy.length()-1;
        for(int i=0;i<=j;i++){
            if(copy[i]!=copy[j]){
                 return false;
            }
            j--;
        }
        return true;
        //return equal(copy.begin(),copy.end(),copy.rbegin());
    }
};
