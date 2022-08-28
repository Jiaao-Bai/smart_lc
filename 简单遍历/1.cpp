/*
2020.5.13
给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。

示例:
给定 nums = [2, 7, 11, 15], target = 9
因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]

借助散列表，边摆数据边查找，一遍遍历结束
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hashMap;
        vector<int> result;
        for(int i=0; i<nums.size(); i++){
            auto it = hashMap.find(target-nums[i]);
            if(it == hashMap.end()){
                hashMap[nums[i]]=i;
            }else{
                result.push_back(i);
                result.push_back(it->second);
                return result;
            }
        }
        return result;
    }
};