#include "header.hpp"

class Solution {
    
public:
    /*超过时间复杂度
    int jump_with_map(std::vector<int>& nums, int begin, std::map<int, int>& map){
        int min_jump_times = -1;

        if(map.find(begin)!=map.end()){
            return map[begin];
        }

        if(begin==nums.size()-1){
            map[begin]=0;
            return 0;
        }

        if(nums[begin]==0){
            map[begin]=-1;
            return -1;
        }

        for(int i=1; i<=nums[begin]; i++){
            if(begin+i<nums.size()){
                auto try_times = jump_with_map(nums, begin+i, map);
                if(try_times!=-1){
                    if(min_jump_times==-1){
                        min_jump_times = try_times+1;
                    }else if(try_times+1<min_jump_times){
                        min_jump_times = try_times+1;
                    }
                }
            }else{
                break;
            }
        }

        map[begin] = min_jump_times;
        return std::move(min_jump_times);
    }

    int jump(std::vector<int>& nums) {
        //保存每个位置可以跳到最后的次数
        std::map<int, int> map_;
        return jump_with_map(nums, 0, map_);
    }*/
    //寻找1次，2次，n次jump之后最大位置
    int jump(std::vector<int>& nums) {
        int steps = 0;
        int edge_for_steps = 0;
        int max_range_for_next_step = 0;
        int i=0;
        while(i<nums.size()){
            if(edge_for_steps<i){
                steps++;
                edge_for_steps = max_range_for_next_step;
            }
            //选择一个最大的作为下一个step的范围
            max_range_for_next_step = std::max(i+nums[i], max_range_for_next_step);
            i++;
        }
        return steps;
    }
};