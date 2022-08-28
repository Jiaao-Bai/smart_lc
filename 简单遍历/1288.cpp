/*
1288. 删除被覆盖区间
//时间24空间100
//另一种方法：先按左边界排序，然后从做到右记录一个最远覆盖值然后遍历一遍
//提示可以用扫描线算法去解，不过暂时没看懂

给你一个区间列表，请你删除列表中被其他区间所覆盖的区间。

只有当 c <= a 且 b <= d 时，我们才认为区间 [a,b) 被区间 [c,d) 覆盖。

在完成所有删除操作后，请你返回列表中剩余区间的数目。

 

示例：

输入：intervals = [[1,4],[3,6],[2,8]]
输出：2
解释：区间 [3,6] 被区间 [2,8] 覆盖，所以它被删除了。

 

提示：​​​​​​

    1 <= intervals.length <= 1000
    0 <= intervals[i][0] < intervals[i][1] <= 10^5
    对于所有的 i != j：intervals[i] != intervals[j]
*/
#include "leetcodeheader"
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        map<int, int> searchTree;
        int res = 0;
        bool processed = false;
        for(auto e: intervals){
            for(auto i = searchTree.begin(); i!=searchTree.upper_bound(e[0]); i++){
                if(e[1]<=(*i).second){
                    res++;
                    processed = true;
                    break;
                }
            }
            auto i = searchTree.lower_bound(e[0]);
            while(i!= searchTree.end()){
                if(e[1]>=(*i).second){
                    res++;
                    auto forErase = i;
                    i++;
                    searchTree.erase(forErase);
                }else{
                    i++;
                }
            }
            if(processed == true){
                processed = false;
            }else{
                pair<int, int> tempPair(e[0], e[1]);
                searchTree.insert(tempPair);                
            }
        }
        return (int)intervals.size()-res;
    }
};

int main(){
    vector<vector<int>> input = {{1,4},{3,6},{2,8}};
    int res;
    res = Solution().removeCoveredIntervals(input);
    cout<<res<<endl;
    return 0;
}