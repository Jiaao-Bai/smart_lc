class Solution {
public:

    int firstMissingPositive(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
            int val = nums[i];
            while(val>0 && val<=nums.size() && val!=nums[val-1]){
                int new_val = nums[val-1];
                nums[val-1] = val;
                val = new_val;
            }
        }
        for(int i=0; i<nums.size(); i++){
            if(nums[i]!=i+1){
                return i+1;
            }
        }
        return nums.size()+1;
    }
};