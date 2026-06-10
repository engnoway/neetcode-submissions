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
        string result="";
        for(auto ch:s){
            if(isalnum(ch)){
                result+=tolower(ch);
            }
        }
        return equal(result.begin(),result.end(),result.rbegin());
    }
};
