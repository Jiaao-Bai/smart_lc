/*
最初记事本上只有一个字符 'A' 。你每次可以对这个记事本进行两种操作：

    Copy All（复制全部）：复制这个记事本中的所有字符（不允许仅复制部分字符）。
    Paste（粘贴）：粘贴 上一次 复制的字符。

给你一个数字 n ，你需要使用最少的操作次数，在记事本上输出 恰好 n 个 'A' 。返回能够打印出 n 个 'A' 的最少操作次数。

 

示例 1：

输入：3
输出：3
解释：
最初, 只有一个字符 'A'。
第 1 步, 使用 Copy All 操作。
第 2 步, 使用 Paste 操作来获得 'AA'。
第 3 步, 使用 Paste 操作来获得 'AAA'。

*/
class Solution {
public:
    //刚刚paste结束的状态
    int minStepsWithMap(map<int, map<int, int>> map, int copyd_size, int left_to_need, int ori_length){
        if(left_to_need==0){
            return 0;
        }
        if(left_to_need==copyd_size){
            return 1;
        }
        if(left_to_need==ori_length-left_to_need){
            return 2;
        }
        if(ori_length-left_to_need>left_to_need){
            if(left_to_need%copyd_size==0){
                return left_to_need/copyd_size;
            }else{
                return -1;
            }
        }
        if(copyd_size>left_to_need){
            //不可能实现了
            return -1;
        }

        auto it = map.find(copyd_size);
        if(it!=map.end()){
            auto it2 = it->second.find(left_to_need);
            if(it2!=it->second.end()){
                return it2->second;
            }
        }
        //执行一次粘贴
        int left_to_need_imm = left_to_need-copyd_size;
        int steps_imm = minStepsWithMap(map, copyd_size, left_to_need_imm, ori_length);
        if(steps_imm!=-1){
            steps_imm++;
        }
        //执行一次复制再粘贴
        int copyd_size_new = ori_length-left_to_need;
        int left_to_need_new = left_to_need-copyd_size_new;
        int steps_twice = minStepsWithMap(map, copyd_size_new, left_to_need_new, ori_length);
        if(steps_twice!=-1){
            steps_twice+=2;
        }
        if(steps_imm==-1&&steps_twice==-1){
            map[copyd_size][left_to_need]=-1;
            return -1;
        }else{
            if(steps_imm==-1){
                map[copyd_size][left_to_need]=steps_twice;
                return steps_twice;
            }
            if(steps_twice==-1){
                map[copyd_size][left_to_need]=steps_imm;
                return steps_imm;
            }
            map[copyd_size][left_to_need]= (steps_imm<steps_twice)?steps_imm:steps_twice;
            return map[copyd_size][left_to_need];
        }
    }

    int minSteps(int n) {
        map<int, map<int, int>> map_;
        int op=2;

        if(n==1){
            return 0;
        }
        if(n==2){
            return 2;
        }

        op+=minStepsWithMap(map_, 1, n-2, n);
        return op;
    }
};