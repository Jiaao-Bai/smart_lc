class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        /*
        sort(nums.begin(), nums.end());
        return nums[nums.size()-k];
        */
        make_heap(nums.begin(), nums.end());
        for(int i=0; i<k-1; i++){
            pop_heap(nums.begin(), nums.end());
            nums.pop_back();
        }
        pop_heap(nums.begin(), nums.end());
        return nums.back();
    }
};

class Solution {
public:
    //f(0, 6, 1)
    int f(vector<int>& input, int i, int j, int k){
        std::cout<<i<<" "<<j<<std::endl;
        int ret;
        if(i==j){
            return input[i];
        }

        int target = input[i];//7
        int target_index;
    
        vector<int> bigger;
        vector<int> smaller;

        int it;

        for(it=i+1; it<=j; it++){
            if(input[it]>=target){
                bigger.push_back(input[it]);
            }else{
                smaller.push_back(input[it]);
            }
        }

        for(it=0; it<bigger.size(); it++){
            input[i+it] = bigger[it];
        }

        input[i+it] = target;//index错误
        target_index = i+it;

        for(it=0; it<smaller.size(); it++){
            input[target_index+it+1] = smaller[it];
        }

        if(target_index==k){
            return target;
        }else if(target_index>k){
            ret =  f(input, i, target_index-1, k);
            return ret;
            //return f(input, i, target_index-1, k);
        }else{
            ret = f(input, target_index+1, j, k);
            return ret;
            //return f(input, target_index+1, j, k);
        }
    }


    int findKthLargest(vector<int>& nums, int k) {
        //f(0, 6, 1)
        return f(nums, 0, nums.size()-1, k-1);
    }
};