class Solution {
public:
    bool judge(TreeNode* A, TreeNode* B){
        if(!B){
            return true;
        }
        if(!A || A->val!=B->val){
            return false;
        }
        return judge(A->left, B->left) && judge(A->right, B->right);
    }

    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(!A || !B){
            return false;
        }
        return judge(A, B)||isSubStructure(A->left, B)||isSubStructure(A->right, B); 
    }
};