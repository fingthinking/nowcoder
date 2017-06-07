#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool Find(int target, vector<vector<int>> array) {
        // 从右上角依次向左遍历
        int row_size = array.size()-1;
        int col = array[0].size() - 1;
        int row = 0;
        while (row <= row_size && col >= 0) {
            if (target == array[row][col]) {
                return true;
            }
            if (target < array[row][col]) {
                col--;
            } else {
                row++;
            }
        }
        return false;
    }
};

//int main() {
//    Solution s;
//    vector<vector<int>> vc = {{1, 2, 3, 4, 5},
//                              {2, 4, 6, 7, 8},
//                              {3, 4, 5, 8, 10}};
//    cout << s.Find(9, vc);
//}