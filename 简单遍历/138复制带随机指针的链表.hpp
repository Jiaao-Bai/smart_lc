class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_multimap<Node*, Node*> map_;

        if(head==nullptr){
            return nullptr;
        }
        
        auto new_head = new Node(head->val);
        auto old_current = head;
        auto new_current = new_head;
        if(old_current->random){
            map_.insert({old_current->random, new_current});
        }
        new_current->random = nullptr;
        old_current = old_current->next;

        while(old_current){
            auto node = new Node(old_current->val);
            new_current->next = node;
            new_current = node;
            new_current->random = nullptr;
            if(old_current->random){
                map_.insert({old_current->random, new_current});
            }
            old_current = old_current->next;
        }
        new_current->next = nullptr;
        old_current = head;
        new_current = new_head;

        while(old_current){
            auto it = map_.find(old_current);
            while(it!=map_.end()){
                ((Node*)(it->second))->random = new_current;
                map_.erase(it);
                it = map_.find(old_current);
            }
            old_current = old_current->next;
            new_current = new_current->next;
        }

        return new_head;
    }
};