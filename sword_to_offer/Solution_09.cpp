#include <iostream>

class Solution {
public:
    int jumpFloorII(int number) {
        // f(n) = f(n-1)+f(n-2)+...+f(1)+1
        if (number <= 0) {
            return 0;
        }
        int sum = 1;
        while (number-- > 0) {
            sum += jumpFloorII(number);
        }
        return sum;
    }
};