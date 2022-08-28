/*
84. 柱状图中最大的矩形
给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。
求在该柱状图中，能够勾勒出来的矩形的最大面积。
以上是柱状图的示例，其中每个柱子的宽度为 1，给定的高度为 [2,1,5,6,2,3]。
图中阴影部分为所能勾勒出的最大矩形面积，其面积为 10 个单位。
示例:

输入: [2,1,5,6,2,3]
输出: 10

//g++ -g 84.cpp -o test  -std=c++11 2> error.txt
//时间47空间100
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <stack>
using namespace std;
/*超出内存,00000+一个大数
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> temp;
        int maxsize = 0;
        for(vector<int>::iterator i = heights.begin();i != heights.end(); i++){
            if(*i<0){
                return 0;
            }
            if(*i > temp.size()){
                if(temp.size()!=0){
                    for(vector<int>::iterator j = temp.begin(); j != temp.end(); j++){
                        *j += (j-temp.begin()+1);
                        if(*j >= maxsize){
                            maxsize = *j;
                        }
                    }
                }
                for(int j = temp.size()+1; j <= *i; j++){
                    temp.push_back(j);
                    if(j >= maxsize){
                        maxsize = j;
                    }
                }
            }else{
                for(vector<int>::iterator j = temp.begin(); j < temp.begin()+*i; j++){
                    *j += (j-temp.begin()+1);
                    if(*j >= maxsize){
                        maxsize = *j;
                    }
                }
                temp.erase(temp.begin()+*i,temp.end());
            }
        }
        return maxsize;
    }
};*/
/* 还是超内存。。全是大数
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> temp;
        int maxsize = 0;
        int k = 0;
        int heightforupdate = 0;
        for(vector<int>::iterator i = heights.begin();i != heights.end(); i++){
            if(*i<0){
                return 0;
            }
            if(*i>temp.size()){
                if(temp.size()!=0){
                    for(vector<int>::iterator j = temp.begin(); j != temp.end(); j++){
                        *j += (j-temp.begin()+1);
                        if(*j >= maxsize){
                            maxsize = *j;
                        }
                    }
                }
                if(i==heights.end()-1 || temp.size()>=*(i+1)){
                    //do nothing
                }else   if(*i > *(i+1)){
                            heightforupdate = *(i+1);
                        }else{
                            heightforupdate = *i;
                        }
                for(k=temp.size()+1; k<=heightforupdate; k++){
                    temp.push_back(k);
                }
                if(*i >= maxsize){
                    maxsize = *i;
                }
            }else{
                for(vector<int>::iterator j = temp.begin(); j < temp.begin()+*i; j++){
                    *j += (j-temp.begin()+1);
                    if(*j >= maxsize){
                        maxsize = *j;
                    }
                }
                temp.erase(temp.begin()+*i,temp.end());
            }
        }
        return maxsize;
    }
};*/
//频频超出内存要求的原因是空间复杂度和输入的数值相关。。。
//归并能达到nlogn
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<vector<int>::iterator> temp;
        int maxSize = 0;
        int tempSize = 0;
        vector<int>::iterator tempHight;
        if(heights.size()==0){
            return 0;
        }
        vector<int>::iterator currentLocate;
        for(currentLocate=heights.begin();currentLocate!=heights.end();currentLocate++){
            if(temp.size()==0||*temp.top()<=*currentLocate){
                temp.push(currentLocate);
            }else{
                //判断大小在前，不然后面就是一个段错误
                while((temp.size()>0)&&(*temp.top()>=*currentLocate)){
                    tempHight = temp.top();
                    temp.pop();
                    if(temp.size()>0){
                        tempSize = (*tempHight)*(currentLocate-temp.top()-1);
                    }else{
                        tempSize = (*tempHight)*(currentLocate-heights.begin());
                    }
                    if(maxSize<tempSize){
                        maxSize=tempSize;
                    }
                }
                temp.push(currentLocate);
            }
        }
        while(temp.size()>0){
            tempHight = temp.top();
            temp.pop();
            if(temp.size()>0){
                tempSize = (*tempHight)*(currentLocate-temp.top()-1);
            }else{
                tempSize = (*tempHight)*(currentLocate-heights.begin());
            }
            if(maxSize<tempSize){
                maxSize=tempSize;
            }
        }
        return maxSize;        
    }
};
//playground
void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> heights = stringToIntegerVector(line);
        
        int ret = Solution().largestRectangleArea(heights);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}