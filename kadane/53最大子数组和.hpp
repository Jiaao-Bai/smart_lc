class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ret = nums[0];
        int curMax = 0;
        for(auto& e:nums){
            curMax = max(curMax+e, e);
            ret = max(curMax, ret);
        }
        return ret;
    }
};