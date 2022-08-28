/*
2020.5.14
查找+遍历，实时更新最优解
    新字符的遍历肯定是n没跑了，问题是当前字符串用什么保存，直接保存字符串吧要遍历，我想用散列表，但是不好舍弃重复字符之前的结果。
    ps:散列表还是可以的，每个字符格子保存字符的位置，然后就可以直接跳转到这个位置舍弃之前的结果了
    还是直接保存字符串吧，因为无重复子串最大也就26个
    也可以理解为滑动窗口

性能不是很好，感觉和用了unordered_map有关
2021.12.3 修改
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> alphabet;
        int resultLength = 0, currentLength = 0;
        int beginOfSubString = 0;//滑动窗口左端
        int i;

        for(i=0; i<s.size(); i++){//滑动窗口右端 也可以遍历左端
            auto currentPair = alphabet.find(s[i]);
            if(currentPair == alphabet.end()){
                //not find
                alphabet[s[i]]=i;
                currentLength++;
                if(resultLength<currentLength){
                    resultLength = currentLength;
                }
            }else if(currentPair->second<beginOfSubString){
                alphabet.erase(currentPair);
                alphabet[s[i]]=i;
                currentLength++;
                if(resultLength<currentLength){
                    resultLength = currentLength;
                }
            }else{
                beginOfSubString = currentPair->second+1;
                currentLength = i-currentPair->second;
                alphabet.erase(currentPair);
                alphabet[s[i]]=i;;
            }
        }
        return resultLength;
    }
};