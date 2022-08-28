//双指针，其中一个指针卡在已经遍历过的所有节电中的最大值
//单调栈，保证栈中值的顺序是有序的，因为某个坐标足够高的话左边的数据没有任何影响，所以栈中的数据看起来是单调的
class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> l_to_r;
        vector<int> r_to_l;
        int max=0, ret=0;
        for(auto i=height.begin(); i!=height.end(); i++){
            l_to_r.push_back(max);
            if(*i>max){
                max = *i;
            }
        }
        max = 0;
        for(auto i=height.rbegin(); i!=height.rend(); i++){
            r_to_l.push_back(max);
            if(*i>max){
                max = *i;
            }
        }
        auto n = height.size();
        for(auto i=0; i<height.size(); i++){
            auto edge = min(l_to_r[i], r_to_l[n-1-i]);
            if(edge>height[i]){
                ret += (edge-height[i]);
            }
        }
        return ret;
    }
};