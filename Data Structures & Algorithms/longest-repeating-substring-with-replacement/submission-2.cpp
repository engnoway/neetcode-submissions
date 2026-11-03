class Solution {
   public:
    int characterReplacement(string s, int k) {
        int maxlen = 0;
        //unordered_map<char, int> mp;
int frequency[26]={};
        int left = 0, right = 0, width, maxfreq = 0;
        while (right < s.length()) {
            frequency[s[right]-'A']++;
            maxfreq = max(maxfreq, frequency[s[right]-'A']);
            while (((right-left+1) - maxfreq) > k) {//ivalid window so remove from left charcter
                frequency[s[left]-'A']--;
                left++;
            }
            maxlen = max(maxlen, right-left+1);
            right++;
        }
        return maxlen;
    }
};
