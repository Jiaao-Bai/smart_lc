#include <vector>
#include <set>

vector<int> valid_hour(int x, int y){
    vector<int> ret;
    int input1 = 10*x +y;
    int input2 = 10*y +x;
    if(input1<=23){
        ret.push_back(input1);
    }
    if(input2<=23){
        ret.push_back(input2);
    }
    return ret;
}

vector<int> valid_minute(int x, int y){
    vector<int> ret;
    int input1 = 10*x +y;
    int input2 = 10*y +x;
    if(input1<=59){
        ret.push_back(input1);
    }
    if(input2<=59){
        ret.push_back(input2);
    }
    return ret;
}

void process(set<int>& valid_res, int x, int y, int a, int b){
    auto hours = valid_hour(x, y);
    auto minutes = valid_minute(a, b);
    for(auto& hour:hours){
        for(auto& min:minutes){
            int res = 100*hour+min;
            valid_res.insert(res);
        }
    }
}

int solution(int A, int B, int C, int D) {
    // write your code in C++14 (g++ 6.2.0)
    vector<int> hours, minutes;
    set<int> valid_res;

    process(valid_res, A,B,C,D);
    process(valid_res, C,D,A,B);

    process(valid_res, A,C,B,D);
    process(valid_res, B,D,A,C);

    process(valid_res, A,D,B,C);
    process(valid_res, B,C,A,D);

    return valid_res.size();
}
