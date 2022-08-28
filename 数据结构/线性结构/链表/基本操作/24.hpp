/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* last = nullptr;
        ListNode* i = head;
        ListNode* second;
        while(i!=nullptr && i->next!=nullptr){
            second = i->next;
            i->next = second->next;
            if(last){
                last->next = second;
            }else{
                head = second;
            }
            second->next = i;
            last = i;
            i = i->next;
        }
        return head;
    }
};