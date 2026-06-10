class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen=INT_MIN,right=0,left=0,len=0;
        unordered_set<char>myset;
        while(right<s.length()){
          
            while(myset.count(s[right])){
                myset.erase(s[left]);
                left++;
            }
        myset.insert(s[right]);
        maxlen=max(maxlen,right-left+1);
        right++;

        }
        return maxlen==INT_MIN?0:maxlen;
    }
};
