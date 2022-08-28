class Solution {
public:
    map<char, pair<int, int>> m1; //字符a的子序列出现了几次，最长的子序列的长度
    map<char, int> m2;//字符a的最长允许隔断的子序列是多长

    int process(string& text, int i){
        char target = text[i];
        bool string_break = false;
        int length=1;
        int break_length=1;
        int ret=-1;
        i++;
        while(i<text.size()){
            if(text[i]==target){
                length++;
                break_length++;
                i++;
            }else if(string_break==false){
                string_break=true;
                if(m1.find(target)!=m1.end()){
                    m1[target].first++;
                    m1[target].second = length>m1[target].second?length:m1[target].second;
                }else{
                    m1[target]=make_pair(1,length);
                }
                break_length++;
                length=0;
                ret=i;
                i++;
            }else{
                if(length>0){
                    m2[target]=break_length>m2[target]?break_length:m2[target];
                }
                break;
            }
        }
        if(i==text.size()){
            if(string_break==false){
                if(m1.find(target)!=m1.end()){
                    m1[target].first++;
                    m1[target].second = length>m1[target].second?length:m1[target].second;
                }else{
                    m1[target]=make_pair(1,length);
                }
                return i;   
            }else{
                if(length>0){
                    m2[target]=break_length>m2[target]?break_length:m2[target];
                }
            }
        }
        return ret;
    }
    int maxRepOpt1(string text) {
        int i=0;
        int res=1;
        while(i<text.size()){
            i = process(text, i);
        }
        for(auto& p:m1){
            int count = p.second.second;
            if(p.second.first>1){
                count++;
            }
            res = count>res?count:res;
        }
        for(auto& p:m2){
            if(m1[p.first].first>2){
                res = p.second>res?p.second:res;
            }else{
                res = p.second-1>res?p.second-1:res;
            }
        }
        return res;
    }
};