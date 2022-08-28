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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        vector<int> res;
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        if(root){
            q1.push(root);
        }
        
        while(!q1.empty()||!q2.empty()){
            if(q2.empty()){
                while(!q1.empty()){
                    auto node = q1.front();
                    res.push_back(node->val);
                    if(node->left){
                        q2.push(node->left);
                    }
                    if(node->right){
                        q2.push(node->right);
                    }
                    q1.pop();
                }
                ret.push_back(res);
                res.clear();
            }else{
                while(!q2.empty()){
                    auto node = q2.front();
                    res.push_back(node->val);
                    if(node->left){
                        q1.push(node->left);
                    }
                    if(node->right){
                        q1.push(node->right);
                    }
                    q2.pop();
                }
                ret.push_back(res);
                res.clear();
            }
        }
        return ret;
    }
};