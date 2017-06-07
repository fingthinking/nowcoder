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
    ListNode *Merge(ListNode *pHead1, ListNode *pHead2) {
        // 归并排序
        ListNode *pList = NULL; // 注意初始化
        ListNode *head = NULL;
        while (pHead1 != NULL && pHead2 != NULL) {
            if (pHead1->val < pHead2->val) {
                if (pList == NULL) {
                    pList = pHead1;
                    head = pList;
                } else {
                    pList->next = pHead1;
                    pList = pList->next;
                }
                pHead1 = pHead1->next;
            } else {
                if (pList == NULL) {
                    pList = pHead2;
                    head = pList;
                } else {
                    pList->next = pHead2;
                    pList = pList->next;
                }
                pHead2 = pHead2->next;
            }
        }
        if (pHead1 != NULL) {
            if (pList == NULL) {
                pList = pHead1;
                head = pList;
            } else {
                pList->next = pHead1;
            }
        }
        if (pHead2 != NULL) {
            if (pList == NULL) {
                pList = pHead2;
                head = pList;
            } else {
                pList->next = pHead2;
            }
        }
        return head;
    }
};