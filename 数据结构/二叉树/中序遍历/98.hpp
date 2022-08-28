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
    void sort(TreeNode* node, std::vector<int>& sorted){
        if(node->left){
            sort(node->left, sorted);
        }
        sorted.push_back(node->val);
        if(node->right){
            sort(node->right, sorted);
        }
    }
    bool isValidBST(TreeNode* root) {
        std::vector<int> sorted;
        int last;

        sort(root, sorted);
        if(sorted.size()==1){
            return true;
        }
        last = sorted[0];
        for(int i=1; i<sorted.size(); i++){
            if(last>=sorted[i]){
                return false;
            }
            last = sorted[i];
        }
        return true;
    }
};