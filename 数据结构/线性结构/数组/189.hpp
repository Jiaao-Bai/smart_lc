class Solution {
public:
    void reverse(vector<int>& nums, int i, int j) {
        while(i<j) {
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
        return;
    }

    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        if(k == 0) {
            return;
        }
        reverse(nums, 0, nums.size()-1);
        reverse(nums, 0, k-1);
        reverse(nums, k, nums.size()-1);
        return;
    }
};

