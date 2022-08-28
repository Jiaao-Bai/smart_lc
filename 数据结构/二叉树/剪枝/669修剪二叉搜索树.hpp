
class Solution {
public:
    int low_=0;
    int high_=0;

    TreeNode* process(TreeNode* root, int min, int max){
        if(root==nullptr){
            return root;
        }
        if(root->val<low_){
            return process(root->right, root->val, max);
        }
        if(root->val>high_){
            return process(root->left, min, root->val);
        }
        if(min<low_){
            root->left = process(root->left, min, root->val);
        }
        if(max>high_){
            root->right = process(root->right, root->val, max);
        }
        return root;
    }
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        low_ = low;
        high_ = high;
        return process(root, INT_MIN, INT_MAX);
    }
};