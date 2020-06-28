// 输入两个链表，找出它们的第一个公共结点。
// （注意因为传入数据是链表，所以错误测试数据的提示是用其他方式显示的，保证传入数据是正确的）


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
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        int length1=GetLength(pHead1);
        int length2=GetLength(pHead2);
        ListNode* pNode1=pHead1;
        ListNode* pNode2=pHead2;
         
        int lengthDif=0;
        if (length1 >= length2) {
            lengthDif = length1 - length2;
            for(int i=0; i<lengthDif; i++)  pNode1 = pNode1->next;
        }
        else {
            lengthDif =  length2 - length1;
            for(int i=0; i<lengthDif; i++)  pNode2 = pNode2->next;
        }
          
        while (pNode1 && pNode2) {
            if (pNode1->val == pNode2->val)  return pNode1;
            pNode1=pNode1->next;
            pNode2=pNode2->next;
        }
        return NULL;
    }
     
    int GetLength(ListNode* pHead) {
        ListNode* pNode = pHead;
        int length=0;
        while(pNode){
            length++;
            pNode=pNode->next;
        }
        return length;
    }
};
