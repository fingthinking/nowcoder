#include <iostream>
#include <vector>

using namespace std;

/**
 * 后序遍历的结构特点如下:
 * 1. 最后一位是根节点,之前的分为左右子树的后序遍历
 * 2. 最后一位是中位数,能够将数组完美的分割成两部分
 */
class Solution {
public:

    bool VerifySquenceOfBST(vector<int> sequence) {
        // 小于两个元素,且不是空序列,直接返回true
        if(sequence.size() == 0){
            return false;
        }
        if(sequence.size() <=2){
            return true;
        }
        int num = sequence[sequence.size() - 1];
        // 判断数组最后一个元素是否能够将数组分隔成两部分
        int sep = -1; // 找到分隔的位置
        for(int i=0; i< sequence.size()-1; i++){
            if(sep == -1){ // 未找到之前
                if(sequence[i] > num){
                    sep = i;
                }
            }else{
                if(sequence[i] < num){
                    return false;
                }
            }
        }
        // 能到这儿说明完美的分隔两部分
        if(sep == -1){
            sep = 0;
        }
        vector<int> left;
        vector<int> right;
        for(int i=0; i<sep; i++){
            left.push_back(sequence[i]);
        };
        for(int i=sep; i<sequence.size()-1; i++){
            right.push_back(sequence[i]);
        };
        bool left_b = true;
        if(left.size() != 0){
            left_b = VerifySquenceOfBST(left);
        }
        bool right_b = true;
        if(right.size() != 0){
            right_b = VerifySquenceOfBST(right);
        }
        return left_b && right_b;
    };

};

int main(){
    vector<int> vec = {1,2,3,4};
    Solution s;
    cout<<s.VerifySquenceOfBST(vec);

}