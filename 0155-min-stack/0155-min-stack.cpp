#include <algorithm>

class MinStack {
public:
    MinStack() {
    
    }
private:
    std::vector<int> stk;
    int min_val=2147483647;
public:
    void push(int value) {
        min_val=(min_val>value)? value:min_val;
        stk.emplace_back(value);
    }
    
    void pop() {
        int val=top();
        if(val==min_val){
            min_val=2147483647;
            for(int i=0;i<stk.size()-1;i++){
                min_val=(min_val>stk[i])? stk[i]:min_val;
            }
        }
        stk.pop_back();
    }
    
    int top() {
        return this->stk.back();
    }
    
    int getMin() {
        return this->min_val;
        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */