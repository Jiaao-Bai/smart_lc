class Solution {
public:
    int res = 0;
    bool process(TreeNode* root, int& min, int& max, int& size){
        size = 1;
        bool balance = true;
        if(root->left){
            int ls;
            auto left_balance = process(root->left, min, max, ls);
            if(!left_balance||max>=root->val){
                balance = false;
            }
            size+=ls;
        }else{
            min = root->val;
        }
        if(root->right){
            int tmp;
            int rs;
            auto right_balance = process(root->right, tmp, max, rs);
            if(!right_balance||tmp<=root->val){
                balance = false;
            }
            size+=rs;
        }else{
            max = root->val;
        }
        cout<<root->val<<" "<<size<<endl;

        res = (balance && size>res)?size:res;
        return balance;
    }
    int largestBSTSubtree(TreeNode* root) {
        if(root){
            int min, max, size;
            process(root, min, max, size);
        }
        return res;
    }
};