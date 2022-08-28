/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    struct Res{
        int a; //该节点被父节点照到
        int b; //该节点未被父节点照到，不需要照到父节点
        int c; //该节点需要照到父节点
    };

    Res dfs(TreeNode* node){
        Res ret;
        if(node->left && node->right){
            auto l = dfs(node->left);
            auto r = dfs(node->right);
            ret.c = 1+ l.a + r.a;
            ret.b = min(ret.c, min(l.c+r.b, l.b+r.c));
            ret.a = min(l.b + r.b, ret.b);
        }else if(node->left||node->right){
            TreeNode* only_son = (node->left)?(node->left):(node->right);
            auto r = dfs(only_son);
            ret.c = 1 + r.a;
            ret.b = min(ret.c, r.c);
            ret.a = min(ret.b, r.b);
        }else{
            ret.a=0;
            ret.b=ret.c=1;
        }
        cout<<ret.a<<" "<<ret.b<<" "<<ret.c<<" "<<endl;
        return ret;
    }

    int minCameraCover(TreeNode* root) {
        if(root==nullptr){
            return -1;
        }
        auto res = dfs(root);
        return res.b;
    }
};