//2020.2.17
//2020.5.30

class Solution {
public:
    int maxArea(vector<int>& heights) {
        int ret = 0;
        int max, height;

        if(heights.empty()){
            return 0;
        }
        auto itx = heights.begin();
        auto ity = heights.end()-1;
        while(itx!=ity){
            max = ity-itx;
            if(*itx>*ity){
                height = *ity;
                ity--;
            }else{
                height = *itx;
                itx++;
            }
            max = max*height;
            if(max>ret){
                ret = max;
            }
        }
        return ret;
    }
};
/*
好像是华为面试写的
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int input;
    int tempSize = 0;
    int largestSize = 0;
    vector<int> allHeights;
    vector<int>::iterator i,j;
    while(cin>>input){
        allHeights.push_back(input);
    }
    if(allHeights.size()<=1){
        goto end;
    }

    i = allHeights.begin();
    j = allHeights.end()-1;

    while(i!=j){
        if(*i<*j){
            tempSize = *i * (j-i);
            while((i+1)!=j&&*(i+1)<*i){
                i++;
            }
            i++;
        }else{
            tempSize = *j * (j-i);
            while(i!=(j-1)&&*(j-1)<*j){
                j--;
            }
            j--;
        }
        if(tempSize>largestSize){
            largestSize = tempSize;
        }
    }
    end:
        cout<<largestSize;
        return 0;
}
*/