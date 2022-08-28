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
    //效率过低
public:
    int maxPathSum(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        int res;
        queue<TreeNode*> q;
        stack<TreeNode*> s;
        q.push(root);
        map<TreeNode*, int> max_sum_map;
        map<TreeNode*, int> node_sum_map;

        while(!q.empty()){
            auto node = q.front();
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
            q.pop();
            s.push(node);
        }
        while(!s.empty()){
            auto node = s.top();
            int a = node->val;
            int b = node_sum_map[node->left];
            int c = node_sum_map[node->right];
            if(!node->left && !node->right){
                max_sum_map[node] = a;
                node_sum_map[node] = a;
            }else if(node->left == nullptr){
                node_sum_map[node] = max(a, a+c);
                if(node_sum_map[node]>max_sum_map[node->right]){
                    max_sum_map[node] = node_sum_map[node];
                }else{
                    max_sum_map[node] = max_sum_map[node->right];
                }
            }else if(node->right == nullptr){
                node_sum_map[node] = max(a, a+b);
                if(node_sum_map[node]>max_sum_map[node->left]){
                    max_sum_map[node] = node_sum_map[node];
                }else{
                    max_sum_map[node] = max_sum_map[node->left];
                }
            }else{
                auto new_node_sum = max(a, a+b);
                new_node_sum = max(new_node_sum, a+c);
                node_sum_map[node] = new_node_sum;
                auto max_node_sum = max(new_node_sum, a+b+c);
                auto child_max_sum = max(max_sum_map[node->left], max_sum_map[node->right]);
                if(max_node_sum>child_max_sum){
                    max_sum_map[node] = max_node_sum;
                }else{
                    max_sum_map[node] = child_max_sum;
                }
            }
            s.pop();
        }
        return max_sum_map[root];
    }
};


class Solution {
public:
    int maxPathSum(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        int res;
        queue<TreeNode*> q;
        stack<TreeNode*> s;
        q.push(root);
        int max_sum = INT_MIN;
        map<TreeNode*, int> node_sum_map;

        while(!q.empty()){
            auto node = q.front();
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
            q.pop();
            s.push(node);
        }
        while(!s.empty()){
            auto node = s.top();
            int a = node->val;
            int b = node_sum_map[node->left];
            int c = node_sum_map[node->right];
            if(!node->left && !node->right){
                max_sum = a>max_sum?a:max_sum;
                node_sum_map[node] = a;
            }else if(node->left == nullptr){
                auto tmp = max(a, a+c);
                node_sum_map[node] = tmp;
                max_sum = tmp>max_sum?tmp:max_sum;
            }else if(node->right == nullptr){
                auto tmp = max(a, a+b);
                node_sum_map[node] = tmp;
                max_sum = tmp>max_sum?tmp:max_sum;
            }else{
                auto new_node_sum = max(a, a+b);
                new_node_sum = max(new_node_sum, a+c);
                node_sum_map[node] = new_node_sum;
                auto max_node_sum = max(new_node_sum, a+b+c);
                max_sum = max_node_sum>max_sum?max_node_sum:max_sum;
            }
            s.pop();
        }
        return max_sum;
    }
};