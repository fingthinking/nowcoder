#include <iostream>
#include <stack>

using namespace std;

/**
 * 用两个堆实现站操作,其原理是通过数据复制实现,插入永远插入stack1中,读取的时候从stack2中读
 */
class Solution {
public:
    void push(int node) {
        // 插入永远插入到stack1
        stack1.push(node);
    }

    int pop() {
        // 读取永远从stack2读取
        if(stack2.empty()){
            while(!stack1.empty()){
                int num = stack1.top();
                stack2.push(num);
                stack1.pop();
            }
        }
        int num = stack2.top();
        stack2.pop();
        return num;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};