//本来解法没问题但是会超时 改完彻底不能跑了
class Solution {
public:
    struct New_node{
        TreeNode* node;
        int size;
    };

    inline void try_push_queue(queue<New_node>& q, TreeNode* input){
        if(input==nullptr){
            if(!q.empty()&&q.back().node==nullptr){
                q.back().size++;
            }else{
                New_node res;
                res.node = nullptr;
                res.size = 1;
                q.push(res);
            }
        }else{
            New_node res;
            res.node = input;
            q.push(res); 
        }
    }
    int widthOfBinaryTree(TreeNode* root) {
        queue<New_node> q;
        New_node new_root;
        new_root.node = root;
        q.push(new_root);
        int layer_size = 1;
        int max_num = 0;
        int current_layer_num = 0;
        int last_null_size=0;
        bool begin_to_count = true;
        int i;

        while(begin_to_count){
            //上一层有数据
            begin_to_count = false;
            current_layer_num = 0;
            last_null_size = 0;
            i=0;
            while(i<layer_size){        
                if(q.front().node){
                    q.pop();
                    i++;
                    if(!begin_to_count){
                        begin_to_count = true;
                    }
                    current_layer_num++;
                    last_null_size = 0;
                    try_push_queue(q, q.front().node->left);
                    try_push_queue(q, q.front().node->right);                   
                }else{
                    int process_size;
                    if(q.front().size+i>layer_size){
                        process_size = layer_size-i;
                        q.front().size -= process_size;
                        i=layer_size;
                    }else{
                        process_size = q.front().size;
                        i+=process_size;
                        q.pop();
                    }
                    if(begin_to_count){
                        current_layer_num+=process_size;
                    }
                    last_null_size+=process_size;
                    if(!q.empty()&&q.back().node==nullptr){
                        q.back().size+=process_size*2;
                    }else{
                        New_node res;
                        res.node = nullptr;
                        res.size = process_size*2;
                        q.push(res);
                    }
                }
            }
            current_layer_num-=last_null_size;
            max_num = (current_layer_num>max_num)?current_layer_num:max_num;
            layer_size*=2;
        }
        return max_num;
    }
};
//这个可以跑
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<TreeNode*> q;
        queue<long long> id_q;
        int min;
        int max;
        int res = INT_MIN;
        int layer_size = 1;

        if(root==nullptr){
            return 0;
        }

        q.push(root);
        id_q.push(0);

        while(layer_size>0){
            min = id_q.front();
            max = id_q.back();
            res = max-min+1>res?max-min+1:res;
            int i=0;
            int first=-1;
            while(i<layer_size){
                auto node = q.front();
                std::cout<<node<<" "<<q.size()<<std::endl;

                auto id = id_q.front();
                q.pop();
                id_q.pop();
                
                if(node->left!=nullptr || node->right!=nullptr){
                    if(first==-1){
                        first=id;
                    }
                    if(node->left){
                        q.push(node->left);
                        id_q.push(2*(id-first));
                    }
                    if(node->right){
                        q.push(node->right);
                        id_q.push(2*(id-first)+1);
                    }
                }
                i++;
            }
            layer_size = q.size();
        }
        return res;
    }
};