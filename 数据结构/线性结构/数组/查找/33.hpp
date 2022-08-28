//有序数组二分查找
class Solution {
public:
    int search_internal(vector<int>& nums, int target, int begin, int end){
        if(begin==end){
            if(target==nums[begin]){
                return begin;
            }else{
                return -1;
            }
        }

        if(nums[begin]<nums[end]){
            if(nums[begin]<=target && target<=nums[end]){
                int mid = (begin+end)/2;
                auto res1 = search_internal(nums, target, begin, mid);
                auto res2 = search_internal(nums, target, mid+1, end);
                if(res1!=-1){
                    return res1;
                }else if(res2!=-1){
                    return res2;
                }else{
                    return -1;
                }
            }else{
                return -1;
            }
        }else{
            if(nums[begin]<=target || target<=nums[end]){
                int mid = (begin+end)/2;
                auto res1 = search_internal(nums, target, begin, mid);
                auto res2 = search_internal(nums, target, mid+1, end);
                if(res1!=-1){
                    return res1;
                }else if(res2!=-1){
                    return res2;
                }else{
                    return -1;
                }
            }else{
                return -1;
            } 
        }
    }

    int search(vector<int>& nums, int target) {
        return search_internal(nums, target, 0, nums.size()-1);
    }
};