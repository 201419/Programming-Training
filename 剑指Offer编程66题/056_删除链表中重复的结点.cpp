// 在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 
// 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5


/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead) {
        if (NULL == pHead) return NULL;
         
        ListNode* pPreNode = NULL;
        ListNode* pNode = pHead;
         
        while (NULL != pNode) {
            ListNode* pNext = pNode->next;
            if (NULL != pNext && pNext->val == pNode->val) {
                int value = pNode->val;
                ListNode* pToBeDel = pNode;
                while (NULL != pToBeDel && value == pToBeDel->val) {
                    pNext = pToBeDel->next;
                    delete pToBeDel;
                    pToBeDel = NULL; pToBeDel = pNext;
                }
                if (NULL == pPreNode) pHead = pNext;
                else pPreNode->next = pNext;
                pNode = pNext;
            } else {
                pPreNode = pNode; pNode = pNext;
            }
        }
        return pHead;
    }
};
