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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> ret;
        if (root == nullptr) {
            return ret;
        }
        q.push(root);
        // std::cout << root << std::endl;
        int i = 1;
        int j = 0;
        while(!q.empty()) {
            for (int k=0; k<i; k++) {
                TreeNode* node = q.front();
                q.pop();
                if (k == i-1) {
                    // std::cout << k << ", " << node << std::endl;
                    ret.push_back(node->val);
                }
                if (node->left != nullptr) {
                    q.push(node->left);
                    j += 1;
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                    j += 1;
                }
            }
            i = j;
            j = 0;
        }
        return ret;
    }
};