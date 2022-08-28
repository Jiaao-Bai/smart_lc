class Solution {
public:
    pair<int, int> dfs(TreeNode* node){
        pair<int, int> l = make_pair(0,0);
        pair<int, int> r = make_pair(0,0);
        pair<int, int> ret;
        if(node->left){
            l = dfs(node->left);
        }
        if(node->right){
            r = dfs(node->right);
        }
        ret.second = l.first+r.first;
        ret.first = max(ret.second, node->val+l.second+r.second);
        return ret;
    }
    int rob(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        return dfs(root).first;
    }
};