class Solution {
public:
    bool isValid(string s) {
        stack<char>stk;
        for(auto ch :s){
            if(ch=='(' || ch=='[' || ch=='{'){
                stk.push(ch);
            }
            if(ch==')' || ch=='}' || ch==']'){
                if(stk.empty())
                return false;
                else {
                    char top=stk.top();
                    stk.pop();
                    if(ch==')' && top!='(' ||
                    ch==']' && top!='[' ||
                    ch=='}' && top!='{' )
                    return false;
                }
            }
        }
        return stk.empty();
    }
};
