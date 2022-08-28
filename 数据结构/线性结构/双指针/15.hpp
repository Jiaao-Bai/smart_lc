#include "header.hpp"
/*
双指针的核心是本来要做两层的循环只需要一层，因为这两个循环变量有相互关系
即使不做二层循环也能找到符合条件的解
前提是这个序列也是本身有序的
*/
/*
class Solution {
public:
    //四重循环 超时
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> cache;
        vector<vector<int>> ret;

        if(nums.empty()){
            return ret;
        }

        sort(nums.begin(), nums.end());

        for(int i=0; i<nums.size(); i++){
            vector<int> current;
            bool stop_sum=false;
            for(int j=0; j!=i; j++){
                
                if(!stop_sum && nums[j]+nums[i]+nums[i]>0){
                    stop_sum = true;
                }
                if(!stop_sum){
                    current.push_back(nums[j]+nums[i]);
                }
                
                for(int k=0; k<cache[j].size(); k++){
                    
                    if(cache[j][k]+nums[i]>0){
                        break;
                    }
                    if(cache[j][k]+nums[i]==0){
                        vector<int> res{nums[i], nums[j], nums[k]};
                        bool find=false;
                        sort(res.begin(), res.end());
                        for(auto& e:ret){
                            if(e==res){
                                find=true;
                            }
                        }
                        if(!find){
                            ret.push_back(res);
                        }
                        break;
                    }
                }
            }
            cache.push_back(current);
        }
        return ret;
    }
};*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;

        if(nums.size()<3){
            return ret;
        }

        sort(nums.begin(), nums.end());

        for(int i=0; i<nums.size()-2; i++){
            int j=i+1;
            int k=nums.size()-1;
            while(j<k){
                auto sum = nums[j]+nums[k]+nums[i];
                if(sum==0){
                    vector<int> res{nums[i], nums[j], nums[k]};
                    bool find=false;
                    for(auto& e:ret){
                        if(e==res){
                            find=true;
                        }
                    }
                    if(!find){
                        ret.push_back(res);
                    }
                    j++;
                    while(j<k&&nums[j]==nums[j-1]){
                        j++;
                    }
                }else if(sum>0){
                    k--;
                    while(j<k&&nums[k]==nums[k+1]){
                        k--;
                    }
                }else if(sum<0){
                    j++;
                    while(j<k&&nums[j]==nums[j-1]){
                        j++;
                    }
                }
            }
        }
        return ret;
    }
};