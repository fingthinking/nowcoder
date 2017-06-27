#include <iostream>
#include <map>

using namespace std;

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;

    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};

/**
 * 复杂链表的复制, 解题思路:
 * 1. 复制A->B->C为A->A'->B->B'->C->C'
 * 2. 复制random
 * 3. 拆分链表
 */
class Solution {
public:
    RandomListNode *Clone(RandomListNode *pHead) {

        RandomListNode *p = pHead;
        // 1. next复制
        while (p != NULL) {
            RandomListNode *tmp = new RandomListNode(p->label);
            tmp->next = p->next;
            p->next = tmp;
            p = tmp->next;
        }
        // 2. random复制
        p = pHead;
        while (p != NULL) {
            if (p->random != NULL) {
                RandomListNode *pNext = p->next;
                pNext->random = p->random->next;
            }
            p = p->next->next;
        }
        // 3.拆分链表
        RandomListNode *head = NULL;

        p = pHead;
        if (p != NULL) {
            head = p->next;
        }
        RandomListNode *cur = head;
        while (p != NULL) {
            p->next = cur->next;
            p = p->next;
            if (p != NULL) {
                cur->next = p->next;
            }
            cur = cur->next;
        }
        return head;
    }
};

int main() {
    RandomListNode *fir = new RandomListNode(1);
    RandomListNode *sec = new RandomListNode(2);
    RandomListNode *three = new RandomListNode(3);
    RandomListNode *four = new RandomListNode(4);
    RandomListNode *five = new RandomListNode(5);
    RandomListNode *six = new RandomListNode(6);
    fir->next = sec;
    sec->next = three;
    three->next = four;
    four->next = five;
    five->next = six;

    fir->random = three;
    sec->random = NULL;
    three->random = fir;
    four->random = six;
    five->random = sec;
    six->random = four;
    Solution s;
    s.Clone(fir);
}