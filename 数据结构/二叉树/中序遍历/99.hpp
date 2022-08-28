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
    TreeNode *first=nullptr, *first_nt=nullptr, *second=nullptr, *last=nullptr;

    void travelsal(TreeNode* node) {
        if(node->left){
            travelsal(node->left);
        }
        if(last){
            if(node->val<last->val){
                if(first==nullptr){
                    first = last;
                    first_nt = node;
                }else{
                    second = node;
                }
            }
        }
        last = node;
        if(node->right){
            travelsal(node->right);
        }
    }

    void recoverTree(TreeNode* root) {
        travelsal(root);
        if(first&&second){
            swap(first->val, second->val);
        }else{
            swap(first->val, first_nt->val);
        }
    }
};