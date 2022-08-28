/*
    //kadane是一种dp
    int maxSubarraySumCircular(vector<int>& A) {
        int total = 0, maxSum = A[0], curMax = 0, minSum = A[0], curMin = 0;
        for (int& a : A) {
            curMax = max(curMax + a, a);
            maxSum = max(maxSum, curMax);
            curMin = min(curMin + a, a);
            minSum = min(minSum, curMin);
            total += a;
        }
        return maxSum > 0 ? max(maxSum, total - minSum) : maxSum;
    }
*/

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        vector<int> merge_nums;
        int flag = -1; //0负数 1非负数
        int max_minus_num= INT_MIN;
        for(auto& e: nums){
            if(e>=0){
                if(flag==1){
                    merge_nums.back() += e;
                }else{
                    merge_nums.push_back(e);
                    flag = 1;
                }
            }else{
                if(e>max_minus_num){
                    max_minus_num = e;
                }
                if(flag==0){
                    merge_nums.back() += e;
                }else{
                    merge_nums.push_back(e);
                    flag = 0;
                }
            }
        }
        if(merge_nums.size()==1){
            if(merge_nums[0]>=0){
                return merge_nums[0];
            }else{
                return max_minus_num;
            }
        }


        int max = INT_MIN;
        for(int i=0; i<merge_nums.size(); i++){
            int sum = 0;
            for(int j=0; j<merge_nums.size(); j++){
                sum += merge_nums[(i+j)%merge_nums.size()];
                if(sum>max){
                    max = sum;
                }
                if(sum<0){
                    break;
                }
            }
        }
        return max;
    }
      
};