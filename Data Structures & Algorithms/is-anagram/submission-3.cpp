class Solution {
public:
    bool isAnagram(string s, string t) {
        // unordered_map<char,int>mp1;
        //         unordered_map<char,int>mp2;
        unordered_map<char,int>freq;

    //    if(s.length() !=t.length()) return false;
    //    sort(s.begin(),s.end());
    //     sort(t.begin(),t.end());
    //     return s==t;
 if(s.length() !=t.length()) return false;
 for(auto ch: s){
    freq[ch]++;
 }
  for(auto ch: t){
    freq[ch]--;
 }
 
 for(auto [ch,count]: freq){
    if(count!=0)return false;
 }
 return true;
    }
};
