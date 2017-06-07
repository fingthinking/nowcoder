#include <vector>

using namespace std;

class Solution {
public:
    void reOrderArray(vector<int> &array) {
        vector<int> vec;
        int odd = 0;
        for (auto item = array.cbegin(); item != array.cend(); item++) {
            if ((*item & 0x1) == 0) {
                // 偶数
                vec.push_back(*item);
            } else {
                array[odd++] = *item;
            }
        }
        for(auto v=vec.cbegin(); v != vec.cend(); v++){
            array[odd++] = *v;
        }
    }
};