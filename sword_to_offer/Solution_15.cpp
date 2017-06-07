#include <iostream>
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
    ListNode *ReverseList(ListNode *pHead) {
        if (pHead == NULL || pHead->next == NULL) {
            // 有0个或1个结点
            return pHead;
        }
        // 至少3个结点
        ListNode *head = pHead;
        ListNode *mid = pHead->next;
        pHead = mid->next;
        head->next = NULL; // 初始化最后一个元素

        while (pHead->next != NULL) {
            mid->next = head;
            head = mid;
            mid = pHead;
            pHead = pHead->next;
        }
        mid->next = head;
        pHead -> next = mid;
        return pHead;
    }
};

int main(){
    ListNode *ls = new ListNode(1);
    ListNode *ls2 = new ListNode(2);
    ls->next = ls2;
    ListNode *ls3 = new ListNode(3);
    ls2->next = ls3;
    ListNode *ls4 = new ListNode(4);
    ls3->next = ls4;

    Solution s;
    ListNode *rs = s.ReverseList(ls);
    while (rs != NULL){
        cout<<rs->val;
        rs = rs->next;
    }
}