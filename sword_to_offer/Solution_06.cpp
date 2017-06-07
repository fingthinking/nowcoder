#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        // 递归二分查找法
        if(rotateArray.size() == 0){
            return 0;
        }
        return findMin(rotateArray, 0, rotateArray.size() - 1);
    }

    int findMin(vector<int> arr, int start, int end) {
        // 如果最后只剩下两个元素,直接比较两个元素即可
        if (end - start <= 1) {
            return arr[start] < arr[end] ? arr[start] : arr[end];
        }
        int mid = (start + end) / 2;
        if (arr[mid] < arr[start]) {
            // 左侧查找
            return findMin(arr, start, mid);
        } else if (arr[mid] > arr[end]) {
            // 右侧查找
            return findMin(arr, mid, end);
        } else {
            // 已经有序
            return arr[start];
        }
    }
};

int main() {
    vector<int> vec = {5,5,6,7,8,1,1,2,2,3,3,3,4,4,4,4};

    Solution s;
    cout << s.minNumberInRotateArray(vec);
}