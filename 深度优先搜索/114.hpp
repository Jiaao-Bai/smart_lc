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
    TreeNode* node_;
    void flatten(TreeNode* root) {
        if(root==nullptr){
            return;
        }
        if(node_==nullptr){
            node_ = root;
        }else{
            node_->left = nullptr;
            node_->right = root;
            node_ = node_ -> right;
        }
        auto left_node = root->left;
        auto right_node = root->right;
        if(left_node){
            flatten(left_node);
        }
        if(right_node){
            flatten(right_node);
        }
        return;
    }
};