#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> vec;
        int row = matrix.size();
        int col = matrix[0].size();

        int left = -1; //左边界
        int top = 0; // 上边界
        int right = col - 1; // 右边界
        int down = row - 1; // 下边界

        int size = row * col;
        while (size > 0) {
            // 从左往右
            for (int i = ++left; i <= right; i++) {
                vec.push_back(matrix[top][i]);
                size--;
            }
            if(size <= 0){
                break;
            }

            // 从上到下
            for (int j = ++top; j <= down; j++) {
                vec.push_back(matrix[j][right]);
                size--;
            };
            if(size <= 0){
                break;
            }
            // 从右到左
            for (int i = --right; i >= left; i--) {
                vec.push_back(matrix[down][i]);
                size--;
            }
            if(size <= 0){
                break;
            }
            // 从下到上
            for (int j = --down; j >= top; j--) {
                vec.push_back(matrix[j][left]);
                size--;
            }
        };
        return vec;
    }
};

int main(){
    vector<vector<int>> v = {
            {1,2},
            {4,3},
    };
    Solution s;
    vector<int> vv = s.printMatrix(v);
    for(auto item = vv.cbegin(); item != vv.cend(); item++){
        cout<<*item<<" ";
    }
}