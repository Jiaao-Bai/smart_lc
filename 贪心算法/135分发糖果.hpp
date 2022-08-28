class Solution {
public:
//超时target = adjust(nums, j, target);
    set<int> special;

    int adjust(vector<int>& nums, int index, int val){
        int res = -1;
        if(index>0 && special.find(index)==special.end()){
            res = (nums[index-1]>nums[index] && val>=nums[index-1])?(val+1):-1;
        }
        nums[index] = val;
        return res;
    }

    int candy(vector<int>& ratings) {
        vector<int> nums(ratings.size(), 1);
        int res=0;

        if(ratings.size()==1){
            return 1;
        }
        for(int i=1; i<ratings.size(); i++){
            if(ratings[i]>ratings[i-1]){
                nums[i] = nums[i-1]+1;
            }else if(ratings[i]==ratings[i-1]){
                special.insert(i);
                nums[i] = 1;
            }else if(nums[i-1]-1>0){
                nums[i] = 1;
            }else{
                nums[i] = nums[i-1]-1;
            }
            
            if(nums[i]<1){
                int target = 1;
                for(int j=i; j>=0; j--){
                    target = adjust(nums, j, target);
                    if(target==-1){
                        break;
                    }
                }
            }
        }
        for(auto& e:nums){
            res += e;
        }
        return res;
    }
};

class Solution {
public:
    set<int> special;

    int adjust(vector<int>& nums, int index, int val){
        int res = -1;
        if(index>0 && special.find(index)==special.end()){
            res = (nums[index-1]>nums[index] && val>=nums[index-1])?(val+1):-1;
        }
        nums[index] = val;
        return res;
    }

    int candy(vector<int>& ratings) {
        vector<int> nums(ratings.size(), 1);
        int res=0;

        if(ratings.size()==1){
            return 1;
        }
        for(int i=1; i<ratings.size(); i++){
            if(ratings[i]>ratings[i-1]){
                nums[i] = nums[i-1]+1>1?nums[i-1]+1:2;
            }else if(ratings[i]==ratings[i-1]){
                special.insert(i);
                nums[i] = 1;
            }else if(nums[i-1]-1>0){
                nums[i] = 1;
            }else{
                nums[i] = nums[i-1]-1;
            }
        }
        int target = -1;
        for(int j=nums.size()-1; j>=0; j--){
            if(target==-1){
                if(nums[j]<1){
                    target=1;
                    target = adjust(nums, j, target);
                }
            }else{
                target = adjust(nums, j, target);
            }
        }
        for(auto& e:nums){
            res += e;
        }
        return res;
    }
};