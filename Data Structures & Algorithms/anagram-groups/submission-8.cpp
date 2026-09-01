class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // vector<vector<string>>output;
        // unordered_map<string,vector<string>>mp;
        // for(auto s : strs){
        //     string key = s;
        //     sort(key.begin(),key.end());
        //     mp[key].push_back(s);
        // }
        // for(auto&[k,v]:mp){
        //     output.push_back(v);
        // }
        // return output;

        vector<vector<string>> output;
        unordered_map<string, vector<string>> mp;

        // for(auto str:strs){
        //     string key=str;
        //     sort(key.begin(),key.end());
        //     mp[key].push_back(str);
        // }

        for (auto str : strs) {
            vector<int> freq(26, 0);

            for (auto ch : str) {
                freq[ch - 'a']++;
            }
            string key;
            for (auto count : freq) {
                key += to_string(count);
                key += "#";
            }
            mp[key].push_back(str);
        }
        for (auto [k, v] : mp) {
            output.push_back(v);
        }
        return output;
    }
};
