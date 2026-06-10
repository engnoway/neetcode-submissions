class Solution {
public:

    string encode(vector<string>& strs) {
        string res="";
        if(strs.empty())return res;
        for(auto word:strs){
            res+=to_string(word.size())+"#"+word;
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> myvect;
        int len=0;
        int i=0,j=0;
        while(i<s.length()){
            j=i;
            while(s[j]!='#'){
                j++;
            }
            len=stoi(s.substr(i,j-i));
            myvect.push_back(s.substr(j+1,len));
            i=j+len+1;
            
        }
        return myvect;
    }
};
