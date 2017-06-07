#include <iostream>

class Solution {
public:
    double Power(double base, int exponent) {
        // 注意exponent为负数的情况
        if (exponent == 0) {
            return 1;
        } else {
            if(base == 0){
                return 0;
            }
            bool nav = false;
            if (exponent < 0) {
                exponent = -exponent;
                nav = true;
            }
            double num = base;
            while (exponent-- > 1) {
                num *= base;
            }

            return nav ? 1 / num : num;
        }
    }
};