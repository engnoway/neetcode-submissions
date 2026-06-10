class Solution {
public:
    bool isPalindrome(string s) {
        // std::istringstream iss(s);
        // string word;
        // vector<string>words;
        // while(iss>>word){
        //     if(isalpha(word))
        //     words.push_back(tolower(word));
        // }
        // return equal(words.begin(),words.end(),words.rbegin());
        // string result="";
        // for(auto ch:s){
        //     if(isalnum(ch)){
        //         result+=tolower(ch);
        //     }
        // }
        //return equal(result.begin(),result.end(),result.rbegin());
        int left=0;
        int right=s.length()-1;
        while(left<right){
            while(left<right && !isalnum(s[left])) left++;
            while(left<right && !isalnum(s[right])) right--;
            if(tolower(s[left++])!=tolower(s[right--]))
            return false;
        }
        return true;
    }
};
