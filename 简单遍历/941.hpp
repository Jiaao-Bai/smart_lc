#include "leetcode/header.hpp"
class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        bool front_half=true;
        auto max_it = arr.begin();
        if(arr.size()<3){
            return false;
        }

        for(auto it = arr.begin()+1; it!=arr.end(); it++){
            if(front_half){
                if(*it==*(it-1)){
                    return false;
                }else if(*it<*(it-1)){
                    front_half = false;
                    max_it = it-1;
                }
            }else{
                if(*it>=*(it-1)){
                    return false;
                }
            }
        }
        if(max_it!=arr.begin()&&max_it!=arr.end()-1){
            return true;
        }else{
            return false;
        }
    }
};