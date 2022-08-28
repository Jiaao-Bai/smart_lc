class Solution {
public:
    int res = 0;
    int process(TreeNode* node){
        int ret;
        int left_length =0;
        int right_length = 0;
        if(node->left){
            auto l = process(node->left);
            if(node->left->val==node->val){
                left_length = l;
            }
        }
        if(node->right){
            auto l = process(node->right);
            if(node->right->val==node->val){
                right_length = l;
            }
        }
        ret = max(left_length, right_length)+1;
        res = left_length+right_length>res?left_length+right_length:res;
        return ret;
    }
    int longestUnivaluePath(TreeNode* root) {
        if(root){
            process(root);
        }
        return res;
    }
};