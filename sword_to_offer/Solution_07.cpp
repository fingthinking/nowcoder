#include <iostream>

class Solution {
public:
    int Fibonacci(int n) {
        int pre = 0, after = 1; // 先设置为0,第一个值为1
        while (n-- > 0) {
            pre = pre+after;
            after = pre-after;
        }
        return pre;
    }
};