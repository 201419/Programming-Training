// 题目描述

// 输入一个链表，反转链表后，输出链表的所有元素。


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
    ListNode* ReverseList(ListNode* pHead) {
        if(pHead==NULL) return pHead;
        ListNode* pre=NULL;  // 暂存前部已反转链表
        ListNode* pReverseHead=pHead;  // 反转链表
        ListNode* p=NULL;  // 暂存后边未反转链表
        while(pReverseHead!=NULL) {
            p = pReverseHead->next;
            pReverseHead->next = pre;
            if(p==NULL) break;
            pre = pReverseHead;
            pReverseHead = p;
        }
        return pReverseHead;
    }
};