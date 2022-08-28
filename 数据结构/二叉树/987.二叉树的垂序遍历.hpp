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
    map<int, map<int, multiset<int>>> m;
    void f(TreeNode* node, int row, int col){
        if(!node){
            return;
        }
        m[col][row].insert(node->val);
        f(node->left, row+1, col-1);
        f(node->right, row+1, col+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ret;
        f(root, 0, 0);
        for(auto& col_map:m){
            vector<int> v;
            for(auto& s: col_map.second){
                for(auto& e:s.second){
                    v.push_back(e);
                }
            }
            ret.push_back(v);
        }
        return ret;
    }
};