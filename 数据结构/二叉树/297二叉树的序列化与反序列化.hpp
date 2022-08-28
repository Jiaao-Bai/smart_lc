/*
        list<string> dataArray;
        string str;
        for (auto& ch : data) {
            if (ch == ',') {
                dataArray.push_back(str);
                str.clear();
            } else {
                str.push_back(ch);
            }
        }
*/
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ret = "";
        string lchild, rchild;

        if(root==nullptr){
            return ret;
        }

        lchild = serialize(root->left);
        rchild = serialize(root->right);

        ret = to_string(root->val);
        ret.push_back('A');
        ret.append(to_string(lchild.size()));
        ret.push_back('A');
        ret.append(lchild);
        ret.append(rchild);
        return ret;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* node = nullptr;
        if(data==""){
            return node;
        }
        auto a1 = data.find('A');
        auto a2 = data.find('A', a1+1);

        int val = stoi(data.substr(0, a1));
        int lchild_size = stoi(data.substr(a1+1, a2-a1-1));
        int rchild_size = data.size()-a2-1-lchild_size;
        node = new TreeNode(val);

        node->left = deserialize(data.substr(a2+1, lchild_size));
        node->right = deserialize(data.substr(a2+lchild_size+1, rchild_size));
        
        return node;
    }
};

