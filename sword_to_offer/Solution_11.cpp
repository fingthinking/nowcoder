class Solution {
public:
    int  NumberOf1(int n) {
        // 二进制表示,n & n-1可以消除一个n的二进制中的1
        int index=0;
        while(n !=0){
            n &= n-1;
            index ++;
        }
        return index;
    }
};