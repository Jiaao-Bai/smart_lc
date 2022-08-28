#include <limits.h>
#include <vector>

class Solution {
public:
    int reverse(int x) {
        bool positive = (x>=0)?true:false;
        int ret=0;
        std::vector<int> nums;
        int base=1;

        if(x==INT_MIN){
            return 0;
        }

        if(!positive){
            x=-x;
        }

        while(x!=0){
            nums.push_back(x%10);
            x=x/10;
        }

        for(auto it=nums.rbegin(); it!=nums.rend(); it++){
            if(base==1000000000){
                if(*it>=3){
                    return 0;
                }
                if(*it==2&&ret>147483647){
                    return 0;
                }
            }
            ret += base*(*it);
            if(ret<0){
                return 0;
            }
            if(base!=1000000000){
                base *= 10;
            }
        }
        if(!positive){
            return -ret;
        }
        return ret;
    }
};