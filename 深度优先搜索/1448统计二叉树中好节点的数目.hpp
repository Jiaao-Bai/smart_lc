class Solution {
public:
    int size_ = 0;
    stack<int> stack_;

    void process(TreeNode* node){
        if(node->val >= stack_.top()){
            size_++;
            stack_.push(node->val);
        }else{
            stack_.push(stack_.top());
        }
        if(node->left){
            process(node->left);
        }
        if(node->right){
            process(node->right);
        }
        stack_.pop();
    }

    int goodNodes(TreeNode* root) {
        if(!root){
            return 0;
        }
        size_++;
        stack_.push(root->val);
        if(root->left){
            process(root->left);
        }
        if(root->right){
            process(root->right);
        }
        return size_;
    }
};
