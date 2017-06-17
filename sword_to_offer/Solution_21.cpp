#include <iostream>
#include <vector>
using namespace std;

/**
 * 解题思路:
 * 模拟出栈顺序,看最终能否使得栈为空
 */
class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if(pushV.size() != popV.size()){
            return false;
        }
        vector<int> stack;
        int index =0;
        for(auto val = pushV.cbegin(); val != pushV.cend(); val++){
            stack.push_back(*val);// 入栈
            while(index < popV.size() && stack.back() == popV[index]){
                stack.pop_back(); // 出栈
                index++;
            }
        }
        return stack.empty(); // 如果最终栈为空,则证明完全吻合.
    }
};