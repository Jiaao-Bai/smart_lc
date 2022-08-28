//2019.12.11微软2019三面
//当时没注意是个n*n的矩阵，事后怎么想都没法原址完成
/*
48. 旋转图像

给定一个 n × n 的二维矩阵表示一个图像。
将图像顺时针旋转 90 度。
说明：
你必须在原地旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要使用另一个矩阵来旋转图像。

示例 1:

给定 matrix = 
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

原地旋转输入矩阵，使其变为:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]

示例 2:

给定 matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
], 

原地旋转输入矩阵，使其变为:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]
*/

class Solution {
public:
    void switch_value_for_n(vector<vector<int>>& matrix, int n, int x, int y){
      int x0 = x, y0 = y;
      int x1 = x0+n-1, y1 = y0;
      int x2 = x1, y2 = y1+n-1;
      int x3 = x0, y3 = y2;
      
      for(int i=0; i<n-1; i++){
        auto node_0 = matrix[y3][x3];
        matrix[y3][x3] = matrix[y2][x2];
        matrix[y2][x2] = matrix[y1][x1];
        matrix[y1][x1] = matrix[y0][x0];
        matrix[y0][x0] = node_0;
        x0++;
        y1++;
        x2--;
        y3--;
      }
    }
    void rotate(vector<vector<int>>& matrix) {
      int n = matrix.size();
      if(n<=1){
        return;
      }
      int x_y=0;
      while(n>=2){
        switch_value_for_n(matrix, n, x_y, x_y);
        n-=2;
        x_y++;
      }
      return;
    }
};