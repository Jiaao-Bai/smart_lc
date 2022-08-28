//也可以迭代
//中序和后序遍历生成搜索树
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        vector<int> sub_inorder;
        vector<int> sub_postorder;
        int i=0;

        TreeNode* root = new TreeNode(postorder.back());

        for(; i<inorder.size(); i++){
            if(inorder[i]==postorder.back()){
                if(!sub_inorder.empty()){
                    root->left = buildTree(sub_inorder, sub_postorder);
                }
                i++;
                sub_inorder.clear();
                sub_postorder.clear();
                break;
            }else{
                sub_inorder.push_back(inorder[i]);
                sub_postorder.push_back(postorder[i]);
            }
        }

        for(; i<inorder.size(); i++){
            sub_inorder.push_back(inorder[i]);
            sub_postorder.push_back(postorder[i-1]);
        }

        if(!sub_inorder.empty()){
            root->right = buildTree(sub_inorder, sub_postorder);
        }
        return root;
    }
};