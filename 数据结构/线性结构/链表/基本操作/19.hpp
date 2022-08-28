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
//双指针好像也可以
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        std::vector<ListNode*> stack;

        if(head==nullptr){
            return head;
        }

        while(head!=nullptr){
            stack.push_back(head);
            head = head->next;
        }
        int size = stack.size();
        if(size==n){
            //删除首个元素
            if(size==1){
                return nullptr;
            }else{
                return stack[1];
            }
        }else{
            stack[size-n-1]->next = stack[size-n]->next;
            return stack[0];
        }
    }
};