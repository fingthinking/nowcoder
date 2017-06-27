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
 * 复杂链表的复制, 解题思路: 利用map存储映射关系,然后复制链表
 */
class Solution {
private:
    map<int,RandomListNode*> m_map;
public:
    RandomListNode *Clone(RandomListNode *pHead) {
        // 如果是NULL,返回NULL
        if (pHead == NULL) {
            return NULL;
        }
        if(m_map[pHead->label] == NULL){
            m_map[pHead->label] = new RandomListNode(pHead->label);
        }
        RandomListNode *mNode = m_map[pHead->label];
        RandomListNode *random = pHead->random;
        if(random != NULL){
            if(m_map[random->label] == NULL){
                m_map[random->label] = new RandomListNode(random->label);
            }
            mNode->random = m_map[random->label];
        }
        mNode->next = Clone(pHead->next);
        return mNode;
    }
};