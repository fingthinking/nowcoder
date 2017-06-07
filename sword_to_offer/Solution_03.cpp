#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;

    ListNode(int x) :
            val(x), next(NULL) {
    }
};

class Solution {
public:
    vector<int> dev;
    vector<int> printListFromTailToHead(ListNode *head) {
        // 递归实现
        if(head != NULL){
            dev = printListFromTailToHead(head->next);
            dev.push_back(head->val);
        }
        return dev;
    }
};
//
//int main() {
//    Solution s;
//    ListNode *head= new ListNode(1);
//    ListNode *sec=new ListNode(2);
//    ListNode *third = new ListNode(3);
//    ListNode *fourth = new ListNode(4);
//
//    head->next = sec;
//    sec->next = third;
//    third->next = fourth;
//
//    auto vec = s.printListFromTailToHead(head);
//    for (auto item = vec.cbegin(); item != vec.cend(); item++) {
//        cout << *item << endl;
//    }
//}