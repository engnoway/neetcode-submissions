class Solution {
   public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        int op1 = 0, op2 = 0, res = 0;
        for (auto ch : tokens) {
            if (ch != "+" && ch != "-" && ch != "*" && ch != "/")
                stk.push(stoi(ch));
            else {
                if (ch == "+") {
                    op1 = stk.top();
                    stk.pop();
                    op2 = stk.top();
                    stk.pop();
                    stk.push(op1 + op2);
                } else if (ch == "-") {
                    op1 = stk.top();
                    stk.pop();
                    op2 = stk.top();
                    stk.pop();
                    stk.push(op2 - op1);
                } else if (ch == "*") {
                    op1 = stk.top();
                    stk.pop();
                    op2 = stk.top();
                    stk.pop();
                    stk.push(op1 * op2);
                } else {
                    op1 = stk.top();
                    stk.pop();
                    op2 = stk.top();
                    stk.pop();
                    stk.push(op2 / op1);
                }
            }
        }
        return stk.top();
    }
};
