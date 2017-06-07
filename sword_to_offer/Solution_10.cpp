class Solution {
public:
    int rectCover(int number) {
        // 依然是斐波那契数列数列
        // f(n) = f(n-1)+f(n-2); 最后一个横着放,或竖着放;横着放,则其他的就是f(n-1),竖着放,则其他的是f(n-2)
        if(number <=0){
            return 0;
        }
        int before = 0, after = 1;
        while (number-- >= 0) {
            before += after;
            after = before-after;
        }
        return before;
    }
};