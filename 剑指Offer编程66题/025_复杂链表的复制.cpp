// 输入一个复杂链表
// （每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针random指向一个随机节点），
// 请对此链表进行深拷贝，并返回拷贝后的头结点。
// （注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）


/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead) {
        if(!pHead)  return NULL;
         
        RandomListNode *pNode = pHead;
        while(pNode) {
            RandomListNode *pCloned = new RandomListNode(pNode->label);
            pCloned->next = pNode->next;
            pNode->next = pCloned;
            pNode = pCloned->next;
        }
         
        pNode = pHead;
        while(pNode) {
            RandomListNode *pCloned = pNode->next;
            if(pNode->random)  pCloned->random = pNode->random->next;
            pNode = pCloned->next;
        }
         
        pNode = pHead;
        RandomListNode *pCloneHead = pHead->next;
        RandomListNode *pCloned = pHead->next;
        pNode->next = pCloned->next;
        pNode = pNode->next;
        while(pNode) {
            pCloned->next = pNode->next;
            pCloned = pCloned->next;
            pNode->next = pCloned->next;
            pNode = pNode->next;
        }
         
        return pCloneHead;
    }
};


// ===================

/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead) {
        if(!pHead)  return NULL;
         
        RandomListNode *pNode = pHead;
        while(pNode) {
            RandomListNode *pCloned = new RandomListNode(pNode->label);
            pCloned->next = pNode->next;
            pNode->next = pCloned;
            pNode = pCloned->next;
        }
         
        pNode = pHead;
        while(pNode) {
            RandomListNode *pCloned = pNode->next;
            if(pNode->random)  pCloned->random = pNode->random->next;
            pNode = pCloned->next;
        }
         
        pNode = pHead;
        RandomListNode *pCloneHead = pHead->next;
        RandomListNode *pCloned;
        while(pNode->next) {
            pCloned = pNode->next;
            pNode->next = pCloned->next;
            pNode = pCloned;
        }
         
        return pCloneHead;
    }
};

// ===================

/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead) {
        if(!pHead)  return NULL;
         
        RandomListNode *pNode = pHead;
        while(pNode) {
            RandomListNode *pCloned = new RandomListNode(pNode->label);
            pCloned->next = pNode->next;
            pNode->next = pCloned;
            pNode = pCloned->next;
        }
         
        pNode = pHead;
        while(pNode) {
            RandomListNode *pCloned = pNode->next;
            if(pNode->random)  pCloned->random = pNode->random->next;
            pNode = pCloned->next;
        }
         
        RandomListNode *pCloneHead = pHead->next;
        RandomListNode *pCloned = pHead;
        while(pCloned->next) {
            pNode = pCloned->next;
            pCloned->next = pNode->next;
            pCloned = pNode;
        }
         
        return pCloneHead;
    }
};
