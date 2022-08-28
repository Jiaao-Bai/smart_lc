class Solution {
public:
    ListNode* try_reverse(ListNode* begin, int k){
        bool find = true;
        ListNode* cu = begin;
        for(int i=0; i<k; i++){
            if(cu->next){
                cu = cu->next;
            }else{
                find = false;
                break;
            }
        }
        if(!find){
            return begin;
        }
        ListNode* last = cu->next;
        cu = begin->next;
        for(int i=0; i<k; i++){
            auto tmp = cu->next;
            cu->next = last;
            last = cu;
            cu = tmp;
        }
        auto ret = begin->next;
        begin->next = last;
        return ret;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode new_head;
        new_head.next = head;
        ListNode* current = &new_head;
        while(true){
            ListNode* new_current = try_reverse(current, k);
            if(new_current==current){
                break;
            }else{
                current = new_current;
            }
        }
        return new_head.next;
    }
};