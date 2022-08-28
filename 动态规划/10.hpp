/*
2019.11.12
    回溯法，举例aaabcd是否匹配a*abc,两个指针各指向字符串然后不断回溯，但是回溯到什么位置是由a*abc决定的，每次回溯到上一个*处，如果上一个*已经遍历过了就继续回溯到上上个*
    时间复杂度肯定不是最优的，因为回溯重来就是重新访问，理论最优性能是n么。。
    我觉得可以，先遍历一遍aaabcd，转换成a3bcd，然后遍历一遍后者，转换成a2+bc,看看是否匹配
    回溯法有一种不考虑全局效果只考虑眼前是否匹配的感觉，就会有重复的情况。分治法同理
        仿佛找到了问题的关键：这种线性的问题都遍历一遍线性结构记录最重要的信息
2020.5.21
    递归，动态规划
10. 正则表达式匹配
*/
#include "header.hpp"

class Solution {
public:
    typedef std::unordered_map<int, std::unordered_map<int, bool>> Map;

    //make sure index<=length
    bool isMatchWithMap(int s_index, int p_index, std::string& s, std::string& p, Map& map){
        bool ret;
        if(map.find(s_index)!=map.end()){
            if(map[s_index].find(p_index)!=map[s_index].end()){
                return map[s_index][p_index];
            }
        }

        if(p_index==p.length()){
            ret = s_index==s.length();
            map[s_index][p_index] = ret;
            return ret;
        }

        if(s_index==s.length()){
            //p is not empty
            auto it = p_index;
            while(it!=p.length() && it+1!=p.length()){
                if(p[it+1]=='*'){
                    it=it+2;
                }else{
                    break;
                }
            }
            ret = it==p.length();
            map[s_index][p_index] = ret;
            return ret;
        }

        if(s[s_index] == p[p_index] || p[p_index]=='.'){
            if(p_index+1!=p.length() && p[p_index+1]=='*'){
                //3 case
                //1. a* represent nothing
                if(isMatchWithMap(s_index, p_index+2, s, p, map)){
                    map[s_index][p_index] = true;
                    return true;
                //2. a* represent only one a
                }else if(isMatchWithMap(s_index+1, p_index+2, s, p, map)){
                    map[s_index][p_index] = true;
                    return true;
                //3. a* represent more than one a
                }else if(isMatchWithMap(s_index+1, p_index, s, p, map)){
                    map[s_index][p_index] = true;
                    return true;
                }else{
                    map[s_index][p_index] = false;
                    return false;        
                }
            }else{
                //most normal case
                if(isMatchWithMap(s_index+1, p_index+1, s, p, map)){
                    map[s_index][p_index] = true;
                    return true;
                }else{
                    map[s_index][p_index] = false;
                    return false;
                }
            }
        }else if(p_index+1!=p.length() && p[p_index+1]=='*' && isMatchWithMap(s_index, p_index+2, s, p, map)){
            map[s_index][p_index] = true;
            return true;
        }else{
            map[s_index][p_index] = false;
            return false;
        }
    }

    bool isMatch(std::string s, std::string p) {
        Map map;
        return isMatchWithMap(0, 0, s, p, map);
    }
};