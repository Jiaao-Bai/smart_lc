/*
20.2.20
1109. 航班预订统计
这里有 n 个航班，它们分别从 1 到 n 进行编号。
我们这儿有一份航班预订表，表中第 i 条预订记录 bookings[i] = [i, j, k] 意味着我们在从 i 到 j 的每个航班上预订了 k 个座位。
请你返回一个长度为 n 的数组 answer，按航班编号顺序返回每个航班上预订的座位数。

 

示例：

输入：bookings = [[1,2,10],[2,3,20],[2,5,25]], n = 5
输出：[10,55,45,25,25]
*/
#include "leetcodeheader"
//g++ -fsanitize=address -fno-omit-frame-pointer  -g 1109_20.2.20.cpp -o test  -std=c++11 2> error.txt
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        int currentSum = 0;
        multimap<int,int> hashTable;
        multimap<int,int>::iterator currentPair;
        vector<int> result;
        int currentFlight = 1;

        for(auto e:bookings){
            hashTable.insert(pair<int,int>(e[0],e[2]));
            hashTable.insert(pair<int,int>(e[1]+1,-e[2]));
        }

        currentPair=hashTable.begin();
        
        while(currentFlight<=n){
            while(currentPair!=hashTable.end()&&(*currentPair).first==currentFlight){
                currentSum += (*currentPair).second;
                currentPair++;
            }
            result.push_back(currentSum);
            currentFlight++;
        }

        return result;
    }
};

int main(){
    vector<vector<int>> bookings = {{1,2,10},{2,3,20},{2,5,25}};
    vector<int> temp = Solution().corpFlightBookings(bookings,3);
    return 0;
}