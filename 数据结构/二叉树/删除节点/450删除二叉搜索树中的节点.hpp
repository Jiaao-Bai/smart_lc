class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==nullptr){
            return nullptr;
        }
        if(root->val==key){
            if(root->right==nullptr){
                return root->left;
            }else if(root->left==nullptr){
                return root->right;
            }else{
                auto last_node = root;
                auto target = last_node->right;
                while(target->left){
                    last_node = target;
                    target = target->left;
                }
                if(last_node==root){
                    root->right->left = root->left;
                    return root->right;
                }else{
                    last_node->left = target->right;
                    target->left = root->left;
                    target->right = root->right;
                    return target;
                }
            }
        }else if(key>root->val){
            root->right = deleteNode(root->right, key);
        }else{
            root->left = deleteNode(root->left, key);
        }
        return root;
    }
};