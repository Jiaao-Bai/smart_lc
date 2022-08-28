//20.2.19
//20.5.28
//2月pass的代码再去试就会超时
//5.29,待施工,需要研究与背包问题的具体联系
/*
494. 目标和

给定一个非负整数数组，a1, a2, ..., an, 和一个目标数，S。现在你有两个符号 + 和 -。对于数组中的任意一个整数，你都可以从 + 或 -中选择一个符号添加在前面。

返回可以使最终数组和为目标数 S 的所有添加符号的方法数。

示例 1:

输入: nums: [1, 1, 1, 1, 1], S: 3
输出: 5
解释: 

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

一共有5种方法让最终目标和为3。

注意:

    数组非空，且长度不会超过20。
    初始的数组的和不会超过1000。
    保证返回的最终结果能被32位整数存下。

*/
#include "leetcodeheader"
#define forDebug
//时间复杂度是2^n的回溯
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int result = 0;
        int sum = 0;
        vector<int>::iterator currentIterator = nums.begin();
        stack<vector<int>::iterator> stackForIterator;
//#ifdef forDebug
        vector<vector<int>::iterator> stackForDebug;
//#endif
        //init
        if(nums.empty()){
            return result;
        }
        sort(nums.begin(),nums.end(),greater<int>());
        //if no result
        for(auto e:nums){
            sum += e;
        }
        if(sum < S){
            return result;
        }
        //判断没有负号的情况下是否+1
        if(sum == S){
            result++;
            cout<<"init case"<<endl;
        }
        //循环
        while(true){
            int tempSum = sum - 2*(*currentIterator);
            if(tempSum==S){
                result++;
                stackForIterator.push(currentIterator);
                //debug begin
                stackForDebug.push_back(currentIterator);
                cout<<"case:"<<result<<",  ";
                    for(int i=0 ;i<stackForDebug.size();i++){
                        cout<<*stackForDebug[i]<<" ";
                    }
                cout<<endl;                
                //debug end
                sum = tempSum;
                currentIterator++;
            }else if(tempSum>S){
                stackForIterator.push(currentIterator);
                stackForDebug.push_back(currentIterator);
                sum = tempSum;
                currentIterator++;
            }else if(tempSum<S){
                currentIterator++;
            }
            
            while(currentIterator==nums.end()){
                if(stackForIterator.empty()){
                    return result;
                }else{
                    currentIterator=stackForIterator.top();
                    stackForIterator.pop();
                    stackForDebug.pop_back();
                    sum += 2*(*currentIterator);
                    currentIterator++;
                }
            }
        }
    }
};

int main(){
    vector<int> input = {11,20,19,3,25,7,30,45,8,11,35,19,29,9,49,14,22,34,12,0};
    //vector<int> input = {3,3,2,1,0,1,2,3,4,5,6};
    int s;
    cin>>s;
    int output = 0;
    output = Solution().findTargetSumWays(input, s);
    cout<<output<<endl;
}
/*
test case
感觉结果是对的，为啥就不能ac
//超出时间限制是结果是对的，时间太长了，不是说死在while里面了
//可能回溯法不太好吧
18
case:1,  6 
case:2,  6 0 
case:3,  5 1 
case:4,  5 1 0 
case:5,  5 1 
case:6,  5 1 0 
case:7,  4 2 
case:8,  4 2 0 
case:9,  4 2 
case:10,  4 2 0 
case:11,  4 1 1 
case:12,  4 1 1 0 
case:13,  3 3 
case:14,  3 3 0 
case:15,  3 3 
case:16,  3 3 0 
case:17,  3 2 1 
case:18,  3 2 1 0 
case:19,  3 2 1 
case:20,  3 2 1 0 
case:21,  3 2 1 
case:22,  3 2 1 0 
case:23,  3 2 1 
case:24,  3 2 1 0 
case:25,  3 3 
case:26,  3 3 0 
case:27,  3 2 1 
case:28,  3 2 1 0 
case:29,  3 2 1 
case:30,  3 2 1 0 
case:31,  3 2 1 
case:32,  3 2 1 0 
case:33,  3 2 1 
case:34,  3 2 1 0 
case:35,  3 2 1 
case:36,  3 2 1 0 
case:37,  3 2 1 
case:38,  3 2 1 0 
case:39,  3 2 1 
case:40,  3 2 1 0 
case:41,  3 2 1 
case:42,  3 2 1 0 
case:43,  2 2 1 1 
case:44,  2 2 1 1 0 
44
*/