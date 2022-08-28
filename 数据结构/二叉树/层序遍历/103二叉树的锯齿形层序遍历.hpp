class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        vector<vector<int>> ret;

        if(root==nullptr){
            return ret;
        }

        s1.push(root);
        vector<int> res;
        while(!s1.empty() || !s2.empty()){
            res.clear();
            while(!s1.empty()){
                auto node = s1.top();
                res.push_back(node->val);
                if(node->left){
                    s2.push(node->left);
                }
                if(node->right){
                    s2.push(node->right);
                }
                s1.pop();
            }
            if(!res.empty()){
                ret.push_back(res);
            }
            
            res.clear();
            while(!s2.empty()){
                auto node = s2.top();
                res.push_back(node->val);
                if(node->right){
                    s1.push(node->right);
                }
                if(node->left){
                    s1.push(node->left);
                }
                s2.pop();
            }
            if(!res.empty()){
                ret.push_back(res);
            }
        }
        return ret;
    }
};