/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> vec;
        printNext(head,vec);
        return vec;
    }
    void printNext(ListNode *head, vector<int> &vec){
        if(head==NULL) return;
        printNext(head->next,vec);
        vec.push_back(head->val);
    }
};