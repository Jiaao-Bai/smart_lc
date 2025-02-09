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
    void search(TreeNode* node, int& ret, int cur_length, bool is_left_child) {
        cur_length++;
        //std::cout << cur_length << std::endl;
        ret = cur_length > ret ? cur_length : ret;

        if (is_left_child) {
            if(node->left != nullptr) {
                search(node->left, ret, 0, true);
            }
            if(node->right != nullptr) {
                search(node->right, ret, cur_length, false);
            }
        } else {
            if(node->left != nullptr) {
                search(node->left, ret, cur_length, true);
            }
            if(node->right != nullptr) {
                search(node->right, ret, 0, false);
            }
        }
    }

    int longestZigZag(TreeNode* root) {
        int ret = 0;
        if(root == nullptr) {
            return ret;
        }
        if(root->left != nullptr) {
            search(root->left, ret, 0, true);
        }
        if(root->right != nullptr) {
            search(root->right, ret, 0, false);
        }
        return ret;
    }
};