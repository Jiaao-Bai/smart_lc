class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        struct Node{
            int val;
            ListNode *n;
            bool operator<(const Node& input) const{
                return (val>input.val);
            }
        };
        priority_queue<Node> q;
        for(auto& l:lists){
            if(l!=nullptr){
                Node node;
                node.val = l->val;
                node.n = l;
                q.push(node);
            }
        }
        ListNode head, *current = &head;
        while(!q.empty()){
            auto node = q.top();
            q.pop();
            current->next = node.n;
            current = current->next;
            if(current->next){
                Node node;
                node.val = current->next->val;
                node.n = current->next;
                q.push(node);
            }
        }
        return head.next;
    }
};