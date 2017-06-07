class Solution {
public:
    int jumpFloor(int number) {
        // f(n) = f(n-1) + f(n-2)
        // 相当于斐波那契数列,  1,2,3,5
        int before = 0, after = 1;
        while (number-- >= 0) {
            before += after;
            after = before-after;
        }
        return before;
    }
};