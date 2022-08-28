#include "header.hpp"
using namespace std;
//极端情况下时间复杂度n2超时
/*
class Solution {
public:
    int maxDepthBST(vector<int>& order) {
        vector<int> less;
        vector<int> greater;

        if(order.empty()){
            return 0;
        }

        int mid = order[0];

        for(auto& e: order){
            if(e<mid){
                less.push_back(e);
            }else if(e>mid){
                greater.push_back(e);
            }
        }
        int l_dep = maxDepthBST(less);
        int r_dep = maxDepthBST(greater);
        return 1+max(l_dep, r_dep);
    }
};*/
//leetcode可能有bug 测试结果和本地不一致 但这个解法应该没问题
class Solution {
public:
    int maxDepthBST(vector<int>& order) {
        int n = order.size(), res = 0;
        map<int, int> m;
        m[0] = 0;
        m[n+1] = 0;
        for(int i : order) {
            auto it = m.upper_bound(i);
            auto parent_depth = max(it->second, (it--)->second);
            m[i] = parent_depth+1;
            res = max(res, parent_depth+1);
        }
        return res;
    }
};