// 给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null。


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
    ListNode* EntryNodeOfLoop(ListNode* pHead) {
        if (NULL == pHead) return NULL;
         
        int len = 1;
        ListNode *slowNode = pHead;
        ListNode *fastNode = pHead->next;
        for (; NULL != slowNode && NULL != fastNode; len++) {
            if (slowNode == fastNode) break;
            slowNode = slowNode->next;
            fastNode = fastNode->next;
            if (NULL != fastNode) fastNode = fastNode->next;
        }
        if (NULL == fastNode) return NULL;
         
        for (fastNode = pHead; len > 0; len--) {fastNode = fastNode->next;}
        for (slowNode = pHead; slowNode != fastNode;) {
            slowNode = slowNode->next;
            fastNode = fastNode->next;
        }
        return slowNode;
    }
};
