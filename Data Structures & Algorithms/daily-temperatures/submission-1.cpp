class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int>out(temperatures.size(),0);
        stack<int>stk;
        int prev=0;
        for(int i=0;i<temperatures.size();i++){
           while(!stk.empty() && temperatures[stk.top()] < temperatures[i]){
                 prev=stk.top();
                 out[prev]=i-prev;
                 stk.pop();
           }
           stk.push(i);
        }
        return out;
    }
};
