class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>mp1;
                unordered_map<char,int>mp2;

    //    if(s.length() !=t.length()) return false;
    //    sort(s.begin(),s.end());
    //     sort(t.begin(),t.end());
    //     return s==t;
 if(s.length() !=t.length()) return false;
 for(auto ch: s){
    mp1[ch]++;
 }
  for(auto ch: t){
    mp2[ch]++;
 }
 return mp1==mp2;
    }
};
