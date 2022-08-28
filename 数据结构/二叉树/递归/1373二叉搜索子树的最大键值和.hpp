class Solution {
public:
    int res_ = INT_MIN;
    bool dfs(TreeNode* root, int& min, int& max, int& sum){
        bool left_balance = true, right_balance = true;
        int sub_edge, sub_sum;
        sum=root->val;

        if(root->left){
            left_balance = dfs(root->left, min, sub_edge, sub_sum);
            sum+=sub_sum;
            if(sub_edge>=root->val){
                left_balance = false;
            }
        }else{
            min = root->val;
        }

        if(root->right){
            right_balance = dfs(root->right, sub_edge, max, sub_sum);
            sum+=sub_sum;
            if(sub_edge<=root->val){
                right_balance = false;
            }
        }else{
            max = root->val;
        }
        
        if(left_balance && right_balance){
            res_ = sum>res_?sum:res_;
            std::cout<<sum<<" "<<root->val<<std::endl;
            return true;
        }else{
            return false;
        }
    }
    int maxSumBST(TreeNode* root) {
        int min, max, sum=0;
        if(root){
            dfs(root, min, max, sum);
        }
        return res_>0?res_:0;
    }
};