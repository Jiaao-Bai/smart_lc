class Solution {
    //错误解
public:
    int lengthOfLIS(vector<int>& nums) {
        int max_num = nums[0];
        int res = 1;
        map<int,int> sub_list{{nums[0],1}};

        if(nums.size()==1){
            return res;
        }
        for(int i=1; i<nums.size(); i++){
            if(nums[i]>max_num){
                max_num = nums[i];
                res++;
                sub_list[max_num]=res;
            }else if(nums[i]<max_num){
                auto it = sub_list.lower_bound(nums[i]);
                auto size = it->second;
                int current = nums[i];
                for(int j=i+1; j<nums.size() && nums[j]<=max_num; j++){
                    if(nums[j]>current){
                        current = nums[j];
                        size++;
                    }
                }
                if(size>sub_list.size()){
                    while(it!=sub_list.end()){
                        sub_list.erase(it);
                        res--;
                        it = sub_list.lower_bound(nums[i]);
                    }
                    res++;
                    max_num = nums[i];
                    sub_list[max_num]=res;
                }
            }
        }
        for(auto& p:sub_list){
            std::cout<<p.first<<" ";
        }
        return res;
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> length(nums.size(), 1);
        int max = 1;
        for(int i=1; i<nums.size(); i++){
            for(int j=0; j<i; j++){
                if(nums[j]<nums[i]){
                    length[i] = length[j]+1 > length[i]? length[j]+1:length[i];
                }
            }
            max = length[i]>max?length[i]:max;
        }
        return max;
    }
};