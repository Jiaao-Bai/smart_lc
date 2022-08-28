

#include "leetcodeheader"
class Solution {
public:
    int dayOfYear(string date) {
        int year,month,day,ret=0;
        int dayInMonth[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
        year = stoi(date.substr(0,4));
        month = stoi(date.substr(5,2));
        day = stoi(date.substr(8,2));
        if(year%4==0&&year!=1900){
            dayInMonth[2] = 29;
        }
        for(int i=0; i<month; i++){
            ret+=dayInMonth[i];
        }
        ret+=day;
        return ret;
    }
};

int main() {
    string line;
    while (getline(cin, line)) {
        int ret = Solution().dayOfYear(line);
        cout<<ret<<endl;
    }
    return 0;
}


