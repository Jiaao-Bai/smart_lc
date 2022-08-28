class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        int max = nums[0];
        int pos=0, neg=0;
        bool pos_exist = false;
        bool neg_exist = false;
        for(auto& e: nums){
            if(e==0){
                pos_exist = false;
                neg_exist = false;
                if(e>max){
                    max = e;
                }
            }else if(e>0){
                //std::cout<<"pos_exist: "<<pos_exist<<", e: "<<e<<std::endl;
                if(pos_exist && pos>1){
                    pos *= e;
                }else{
                    pos = e;
                    pos_exist = true;
                }
                if(pos>max){
                    max = pos;
                }
                if(neg_exist){
                    neg *= e;
                }
            }else if(e<0){
                if(neg_exist && pos_exist){
                    int new_pos = neg * e;
                    int new_neg = pos * e;
                    pos = new_pos;
                    neg = new_neg<e?new_neg:e;
                    if(pos>max){
                        max = pos;
                    }
                    continue;
                }
                if(neg_exist){
                    pos = neg * e;
                    pos_exist = true;
                    neg = e;
                    if(pos>max){
                        max = pos;
                    }
                    continue;
                }
                if(pos_exist){
                    pos_exist = false;
                    neg_exist = true;
                    neg = pos*e<e?pos*e:e;
                    continue;
                }
                if(!neg_exist && !pos_exist){
                    if(e>max){
                        max = e;
                    }
                    neg_exist = true;
                    neg = e;
                    continue;
                }
            }
            //std::cout<<"max: "<<max<<", e: "<<e<<std::endl;
        }
        return max;
    }
};