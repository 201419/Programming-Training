/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};*/
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if (!pListHead || k == 0)  return NULL;
        
        ListNode* p=pListHead;
        for (int i=0; i<k; i++) {
            if(!p) return NULL;
            else p = p->next;
        }
        
        while (p) {
            p = p->next;
            pListHead = pListHead->next;
        }
        return pListHead;
    }
};
