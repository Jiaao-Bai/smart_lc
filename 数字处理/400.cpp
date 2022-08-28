
#include "leetcodeheader"
#include <cmath>
class Solution {
public:

    int findNthDigit(int n) {
        int i=1;
        long long largerThanN = 9;
        int lessThanN = 0;
        int theNum, theNInTheNum;
        int j;
        int res;
        
        while(largerThanN<n){
            i++;
            lessThanN = largerThanN;
            largerThanN += (long long)i*9*(long long)pow(10, i-1);
            //largerThanN += i*9*tmpFunc(i-1);
            //这个地方long long与int做运算 会先把long long试做int 但是int运算会越界，所以必须先把int转为longlong
        }
        theNInTheNum = (n-lessThanN)%i;
        if(theNInTheNum==0){
            theNum = (n-lessThanN)/i+pow(10, i-1)-1;
            return theNum%10;
        }else{
            theNum = (n-lessThanN)/i+pow(10, i-1);
        }

        j = i-theNInTheNum;
        while(j>0){
            theNum = theNum/10;
        }
        res = theNum%10;
        return res;
    }
};
int main(){
    Solution().findNthDigit(10);
    return 0;
}


