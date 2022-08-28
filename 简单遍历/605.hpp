class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int zero_count=0;
        int max_planted=0;
        bool from_begin = true;
        auto it =flowerbed.begin();

        while(it!=flowerbed.end()){
            if(*it==0){
                zero_count++;
                it++;
            }else{
                if(from_begin){
                    max_planted += zero_count/2;
                    from_begin = false;
                }else{
                    if(zero_count>=3){
                        max_planted += (zero_count-1)/2;
                    }
                }
                if(max_planted>=n){
                    return true;
                }
                zero_count=0;
                it++;
            }
        }

        if(zero_count){
            if(from_begin){
                max_planted += (zero_count+1)/2;
            }else{
                max_planted += zero_count/2;
            }
        }

        if(max_planted>=n){
            return true;
        }else{
            return false;
        }
    }
};