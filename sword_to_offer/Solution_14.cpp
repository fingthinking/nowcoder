#include <iostream>

struct ListNode {
    int val;
    struct ListNode *next;

    ListNode(int x) :
            val(x), next(NULL) {
    }
};

class Solution {
public:
    ListNode *FindKthToTail(ListNode *pListHead, unsigned int k) {
        if(k<=0){
            return NULL;
        }
        ListNode *pre = pListHead;
        while (k-- > 1 && pListHead != NULL) {
            // 找到之前的k个元素, 两个元素之间相差k-1个
            pListHead = pListHead->next;
        }
        if(pListHead == NULL){
            pre = NULL;
        }
        while (pListHead != NULL && pListHead->next != NULL) {
            // 走到最后一个元素
            pListHead = pListHead->next;
            pre = pre->next;
        }
        return pre;
    }
};