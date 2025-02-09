class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> a(nums.size()); //包含当前节点的最大金额
        vector<int> b(nums.size()); //不包含当前节点的最大金额
        int ret = 0;

        if (nums.empty()) {
            return ret;
        }

        a[0] = nums[0];
        b[0] = 0;
        ret = nums[0];

        for(int i=1; i<nums.size(); i++){
            a[i] = std::max(a[i-1], b[i-1]+nums[i]);
            b[i] = a[i-1];
            ret = a[i] > ret ? a[i] : ret;
        }
        return ret;
    }
};