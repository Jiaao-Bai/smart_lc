class Solution {
public:
    //cur输入必须有效，输出可能为end
    int find_next_begin(vector<int>& nums, int& cur){
        if(nums[cur]==0){
            while(cur<nums.size()&&nums[cur]==0){
                cur++;
            }
            return 0;
        }else{
            int release_size=0;
            while(cur<nums.size()&&nums[cur]==1){
                cur++;
            }
            while(cur<nums.size()&&nums[cur]==0){
                cur++;
                release_size++;
            }
            return release_size;
        }
    }
    //cur输入必须为1的区间内，输出可能为end
    bool find_next_end(vector<int>& nums, int& cur, int k){
        while(cur<nums.size()&&nums[cur]==1){
            cur++;
        }
        int cur_now = cur-1;
        int zero_size=0;
        while(cur<nums.size()&&nums[cur]==0){
            cur++;
            zero_size++;
        }
        if(cur==nums.end()){
            return false;
        }else if(zero_size<=k){
            k-=zero_size;
            find_next_end(nums, cur, k);
        }
    }

    int longestOnes(vector<int>& nums, int k) {
        int begin=0;
        int end=0;
        int res=0;

        find_next_begin(nums, begin);
        if(begin==nums.end()){
            return nums.size()>k?k:nums.size();
        }
        end = begin;
        find_next_end(nums, end, k);

        
    }
};