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
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        if(pHead1==NULL) return pHead2;
        if(pHead2==NULL) return pHead1;
        ListNode* mergeList=NULL;
        ListNode* mergeListEnd=NULL;
        if(pHead1->val <= pHead2->val) {
            mergeList = pHead1;
            pHead1 = pHead1->next;
        }
        else {
            mergeList = pHead2;
            pHead2 = pHead2->next;
        }
        mergeListEnd = mergeList;
        while(pHead1!=NULL&&pHead2!=NULL) {
            if(pHead1->val <= pHead2->val){
                mergeListEnd->next = pHead1;
                pHead1 = pHead1->next;
            }
            else {
                mergeListEnd->next = pHead2;
                pHead2 = pHead2->next;
            }
            mergeListEnd = mergeListEnd->next;
        }
        if(pHead1==NULL) mergeListEnd->next=pHead2;
        if(pHead2==NULL) mergeListEnd->next=pHead1;
        return mergeList;
    }
};

/* =========================================================== */

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
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if (!pHead1)  return pHead2;
        else if (!pHead2)  return pHead1;
        
        ListNode* pMergeHead = NULL;
        
        if (pHead1->val < pHead2->val) {
            pMergeHead = pHead1;
            pMergeHead->next = Merge(pHead1->next, pHead2);
        }
        else {
            pMergeHead = pHead2;
            pMergeHead->next = Merge(pHead1, pHead2->next);
        }
        
        return pMergeHead;
    }
};
