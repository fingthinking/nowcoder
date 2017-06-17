#include <iostream>
#include <stack>

using namespace std;
class Solution {
private:
    stack<int> min_st;
    stack<int> vals;

public:
    void push(int value) {
        vals.push(value);
        // 如果min_vec中数不小于入栈数据,则不改变
        if(min_st.size() == 0){
            min_st.push(value);
        } else{
            int min = min_st.top();
            if(min > value){
                min_st.push(value);
            }
        }
    }
    void pop() {
        int val = vals.top();
        vals.pop();
        if(val <= min_st.top()){
            min_st.pop();
        }
    }
    int top() {
        return vals.top();
    }
    int min() {
        return min_st.top();
    }
};