/*
类似的题 阿里云技术面
给定一个m*n的矩阵，请找到此矩阵的一个子矩阵，并且此子矩阵的各个元素的和最大，输出这个最大的值。
Example：
0 -2 -7 0
9 2 -6 2
-4 1 -4 1
-1 8 0 -2
其中左上角的子矩阵：
9 2
-4 1
-1 8
此子矩阵的值为9+2+(-4)+1+(-1)+8=15。
*/
int f(vector<int>& input){
  int max = input[0];
  int cur = input[0];
  for(int i=1; i<input.size(); i++){
    if(cur>0){
      cur+=input[i];
    }else{
      cur=input[i];
    }
    max = cur>max?cur:max;
  }
  return max;
}
int process(vector<vector<int>>& input){
  int res = input[0][0];
  for(int i=0; i<input[0].size(); i++){
    for(int j=i; j<input[0].size(); j++){
      vector<int> vec;
      for(int k=0; k<input.size(); k++){
        int val=0; 
        for(int p=i; p<=j; p++){ //0+ -2 + -7 +0 //
          val += input[k][p];
        }
        vec.push_back(val);
      }
      //一维vec
      int cur = f(vec);
      res = cur>res?cur:res;
    }
  }
  return res;
}

