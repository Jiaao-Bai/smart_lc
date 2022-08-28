/*
2020.5.20
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

示例 1：

输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。

示例 2：

输入: "cbbd"
输出: "bb"
遍历一遍，每次把可以继续边长的的子串存到列表里，当处理下一个字符时判断是否满足列表里现有子串的要求
时间25，空间75，可以预见比较适合无序性比较高，回文子串非常小的长字符串
也可以动态规划，以s的长度创建二维bool数组，总共子串个数也就n方个，a[i][j]保存i到j是不是回文的
    if(s[i]==s[j])
    {
        if(i-j<3)//如果如果两个相等字符之间只有一个字符，那么一定回文
        {
            res[j][i]=1;
        }
        else
        {
            res[j][i]=res[j+1][i-1];
        }
    }
注意：res[j][i]=res[j+1][i-1];从长度小于自己2的情况构建，要是1就很麻烦
不过时间18空间26都很邋遢+
*/
#include "leetcodeheader"
//七次没pass 重写
class SolutionError {
public:
    string longestPalindrome(string s) {
        list<string::iterator> waitForCmp;
        string::iterator i;
        string::iterator iteratorForMaxLength;
        //string result;
        list<string::iterator>::iterator currentItInList, forDelete;

        int maxLength=0, tmpLength;

        if(s.size()==0){
            return s;
        }
        for(i=s.begin();i!=s.end();i++){
            currentItInList=waitForCmp.begin();//b
            while(currentItInList!=waitForCmp.end()){
            //for(currentItInList=waitForCmp.begin();currentItInList!=waitForCmp.end();currentItInList++){
            //for(auto e: waitForCmp){
                //这个地方有问题，我本想用*currentItInList但是为了简单启用了e
                //but 我对e的改变不会影响到*currentItInList 造成line90 error
                string::iterator e=*currentItInList;
                if(*e==*i){
                    if(e==s.begin()){
                        tmpLength = i-e+1;
                        if(tmpLength>maxLength){
                            maxLength = tmpLength;
                            iteratorForMaxLength = s.begin();
                        }
                        forDelete = currentItInList;
                        currentItInList++;
                        waitForCmp.erase(forDelete);  
                    }else{
                        //for result error
                        //e--;//b
                        (*currentItInList)--;
                    }
                }else{
                    tmpLength = i-e-1;
                    if(tmpLength>maxLength){
                        maxLength = tmpLength;
                        iteratorForMaxLength = e+1;
                    }
                    //fix error in running
                    forDelete = currentItInList;
                    currentItInList++;
                    waitForCmp.erase(forDelete);                        
                }
            }
            waitForCmp.push_back(i);
            //这里漏掉s.begin()单个字符的判断 b
            if(i!=s.begin()){
                waitForCmp.push_back(i-1);
            }
        }
        for(auto e: waitForCmp){
            tmpLength = s.end()-e-1;
            if(tmpLength>maxLength){
                maxLength = tmpLength;
                iteratorForMaxLength = e+1;
            }
        }
        if(maxLength==0){
            return s;
        }else{
            return s.substr(iteratorForMaxLength-s.begin(),maxLength);
        }
    }
};

class Solution {
public:
    string longestPalindrome(string s) {
        list<string::iterator> waitForCmp;//保存所有需要比较的字符，除了单字符的所有情况都需要比较
        string::iterator i;
        string::iterator iteratorForMaxLength;//最长子串起始字符
        list<string::iterator>::iterator currentItInList, forDelete;

        int maxLength=1, tmpLength;

        if(s.size()==0){
            //maxLength至少是1了，所以不去检测1,只找最少是2的情况
            return s;
        }
        for(i=s.begin();i!=s.end();i++){
            currentItInList=waitForCmp.begin();
            while(currentItInList!=waitForCmp.end()){
                string::iterator e=*currentItInList;
                if(*e==*i){
                    if(e==s.begin()){
                        tmpLength = i-e+1;
                        if(tmpLength>maxLength){
                            maxLength = tmpLength;
                            iteratorForMaxLength = s.begin();
                        }
                        forDelete = currentItInList;
                        currentItInList++;
                        waitForCmp.erase(forDelete);  
                    }else{
                        (*currentItInList)--;
                        currentItInList++;
                    }
                }else{
                    tmpLength = i-e-1;
                    if(tmpLength>maxLength){
                        maxLength = tmpLength;
                        iteratorForMaxLength = e+1;
                    }
                    forDelete = currentItInList;
                    currentItInList++;
                    waitForCmp.erase(forDelete);                        
                }
            }
            waitForCmp.push_back(i);
            //这里漏掉s.begin()单个字符的判断 b
            if(i!=s.begin()){
                waitForCmp.push_back(i-1);
            }
        }
        for(auto e: waitForCmp){
            tmpLength = s.end()-e-1;
            if(tmpLength>maxLength){
                maxLength = tmpLength;
                iteratorForMaxLength = e+1;
            }
        }
        if(maxLength==1){
            return s.substr(0,1);
        }else{
            return s.substr(iteratorForMaxLength-s.begin(),maxLength);
        }
    }
};
//抄来的动态规划解法
class Solution {
public:
    string longestPalindrome(string s) {
    int length=s.length();
   if(length<=1)
   {
       return s;
   }
   vector<vector<int>>res (length,vector<int>(length,0));
    //先初始化二维数组（对角线）
   for(int i=0;i<length;i++)
    {
        res[i][i]=1;
    }
    int start=0;//记录最大回文子串的开始位置
    int maxlength=1;//记录最大回文子串的长度
    for(int i=1;i<length;i++)//两层for循环遍历每一个位置到另一个位置的情况
    {
        for(int j=0;j<i;j++)
        {
            if(s[i]==s[j])
            {
                if(i-j<3)//如果如果两个相等字符之间只有一个字符，那么一定回文
                {
                    res[j][i]=1;
                }
                else
                {
                    res[j][i]=res[j+1][i-1];
                }
            }
            if(res[j][i])//当j到i之间的子串回文时判断其长度是否最大，然后更改
            {
                if(i-j+1>maxlength)
                {
                    maxlength=i-j+1;
                    start=j;
                }
            }

        }
    }
    return s.substr(start,maxlength);
  }
};
int main(){
    string input("aaabaaaa");
    string output = Solution().longestPalindrome(input);
    cout<<output<<endl;
    return 0;
}