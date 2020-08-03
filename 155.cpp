class MinStack {
public:
    /** initialize your data structure here. */
    stack <int> main; //keep all numbers in the stack
    stack <int> min; //keep the latest min values

    MinStack() {

    }

    void push(int x) {

        main.push(x);

        // if min stack is empty, push in number
        if(min.empty()) {
            min.push(x);
        }

        // else if stack isn't empty and new number is >= current min, add to min stack
        else if(x <= min.top()) {
            min.push(x);
        }
    }

    void pop() {

        // if we need to pop the min from main stack, remove it from min as well
        if(min.top() == main.top()) {
            min.pop();
        }

        main.pop();
    }

    int top() {
        return main.top();
    }

    int getMin() {
        return min.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
