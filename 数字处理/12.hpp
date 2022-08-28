class Solution {
public:
    void processNum(int& num, string& ret, int base, string c){
        int times;
        times = num/base;

        if(times!=0){
            for(int i=0; i<times; i++){
                ret+=c;
            }
            num -= base*times;
        }
    }

    string intToRoman(int num) {
        string ret;
        processNum(num, ret, 1000, "M");
        processNum(num, ret, 900, "CM");
        processNum(num, ret, 500, "D");
        processNum(num, ret, 400, "CD");
        processNum(num, ret, 100, "C");
        processNum(num, ret, 90, "XC");
        processNum(num, ret, 50, "L");
        processNum(num, ret, 40, "XL");
        processNum(num, ret, 10, "X");
        processNum(num, ret, 9, "IX");
        processNum(num, ret, 5, "V");
        processNum(num, ret, 4, "IV");
        processNum(num, ret, 1, "I");
        return ret;
    }
};