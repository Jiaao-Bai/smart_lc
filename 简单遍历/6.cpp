/*
2020.5.20
将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。

比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：

L   C   I   R
E T O E S I I G
E   D   H   N

之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。

请你实现这个将字符串进行指定行数变换的函数：

string convert(string s, int numRows);

示例 1:

输入: s = "LEETCODEISHIRING", numRows = 3
输出: "LCIRETOESIIGEDHN"

示例 2:

输入: s = "LEETCODEISHIRING", numRows = 4
输出: "LDREOEIIECIHNTSG"
解释:

L     D     R
E   O E   I I
E C   I H   N
T     S     G

2019年年底我说了一句话：用一个二维数组然后摆积木方法一个一个放进去
很蠢，直接四个队列就可以
时间60 空间100
*/

class Solution {
public:
    string convert(string s, int numRows) {
        string eachLine[numRows];
        int currentRow = 0;
        bool forward = true;
        string result;

        if(numRows==1){
            return s;
        }
        for(auto e:s){
            eachLine[currentRow].push_back(e);
            if(forward){
                if(currentRow==numRows-1){
                    forward = false;
                    currentRow--;
                }else{
                    currentRow++;
                }
            }else{
                if(currentRow==0){
                    forward = true;
                    currentRow++;
                }else{
                    currentRow--;
                }                
            }
        }
        for(currentRow=0; currentRow<numRows; currentRow++){
            result += eachLine[currentRow];
        }
        return result;
    }
};