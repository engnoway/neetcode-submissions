class Solution {
   public:
    int characterReplacement(string s, int k) {
        int maxlen = 0;
        unordered_map<char, int> mp;

        int left = 0, right = 0, width, maxfreq = 0;
        while (right < s.length()) {
            mp[s[right]]++;
            width = right - left + 1;
            maxfreq = max(maxfreq, mp[s[right]]);
            while ((width - maxfreq) > k) {
                mp[s[left]]--;
                left++;
                width = right - left + 1;
            }
            maxlen = max(maxlen, right - left + 1);
            right++;
        }
        return maxlen;
    }
};
