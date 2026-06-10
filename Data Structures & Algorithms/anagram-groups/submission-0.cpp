class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string,vector<string>>mp;
        for(const auto &word:strs){
            string sorted=word;
            sort(sorted.begin(),sorted.end());
            mp[sorted].push_back(word);
        }
        for(auto&element:mp){
            result.push_back(element.second);
        }
        return result;
    }
};
