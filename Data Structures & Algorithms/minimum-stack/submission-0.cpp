class MinStack {
   public:
    stack<int> stk;
    stack<int> minstk;

    MinStack() {}

    void push(int val) {
        //if (stk.top() > minstk.top()) minstk.push(val);
        stk.push(val);
        if(minstk.empty())
            minstk.push(val);
        else
            minstk.push(min(val,minstk.top()));
    }

    void pop() {
        stk.pop();
        minstk.pop();
    }

    int top() { return stk.top(); }

    int getMin() { return minstk.top(); }
};
