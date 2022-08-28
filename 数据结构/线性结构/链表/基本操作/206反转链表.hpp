class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* next = nullptr;
        ListNode* current = head;
        while(current){
            ListNode* n = current->next;
            current->next = next;
            next = current;
            current = n;
        }
        return  next;
    }
};