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

//遍历所有叶子节点，同时要保证栈中缓存的都是该叶子节点的父节点
//对于二叉树来讲 深度优先搜索可以用后续遍历实现
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        std::vector<pair<TreeNode*, int>> node_stack;
        int sum=0;
        std::vector<std::vector<int>> ret;

        if(root){
            node_stack.push_back(std::make_pair(root, 0));
            sum += root->val;
        }
        while(!node_stack.empty()){
            auto top_node = node_stack.back().first;
            auto& flag = node_stack.back().second;
            
            if(flag==0){
                flag=1;
                if(top_node->left){
                    node_stack.push_back(std::make_pair(top_node->left, 0));
                    sum += top_node->left->val;
                }
            }else if(flag==1){
                flag=2;
                if(top_node->right){
                    node_stack.push_back(std::make_pair(top_node->right, 0));
                    sum += top_node->right->val;
                }
            }else if(flag==2){
                if(!top_node->left && !top_node->right){
                    //son node
                    if(sum==targetSum){
                        std::vector<int> result;
                        for(auto& e: node_stack){
                            result.push_back(e.first->val);
                        }
                        ret.push_back(result);
                    }
                }
                node_stack.pop_back();
                sum -= top_node->val;
            }
        }
        return ret;
    }
};
//抄来的 dfs的递归实现
class Solution {
public:
    vector<vector<int>> ret;
    vector<int> path;

    void dfs(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return;
        }
        path.emplace_back(root->val);
        targetSum -= root->val;
        if (root->left == nullptr && root->right == nullptr && targetSum == 0) {
            ret.emplace_back(path);
        }
        dfs(root->left, targetSum);
        dfs(root->right, targetSum);
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root, targetSum);
        return ret;
    }
};
