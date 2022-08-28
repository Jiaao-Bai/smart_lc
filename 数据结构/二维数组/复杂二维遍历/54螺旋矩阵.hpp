//很多边界条件
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        if(matrix.empty()){
            return ret;
        }
        if(matrix[0].empty()){
            return ret;
        }
        int size = matrix.size()*matrix[0].size();
        int direction=0; //0,1,2,3
        int d0 = matrix[0].size()-1;
        int d1 = matrix.size()-1;
        int d2 = 0;
        int d3 = 1;
        int i=0, j=0;

        while(true){
            if(direction==0){
                if(j>d0){
                    return ret;
                }
                while(j<d0){
                    ret.push_back(matrix[i][j]);
                    j++;
                }
                ret.push_back(matrix[i][j]);
                d0--;
                i++;
                direction = 1;
            }
            if(direction==1){
                if(i>d1){
                    return ret;
                }
                while(i<d1){
                    ret.push_back(matrix[i][j]);
                    i++;
                }
                ret.push_back(matrix[i][j]);
                d1--;
                j--;
                direction = 2;
            }
            if(direction==2){
                if(j<d2){
                    return ret;
                }
                while(j>d2){
                    ret.push_back(matrix[i][j]);
                    j--;
                }
                ret.push_back(matrix[i][j]);
                d2++;
                i--;
                direction = 3;
            }
            if(direction==3){
                if(i<d3){
                    return ret;
                }
                while(i>d3){
                    ret.push_back(matrix[i][j]);
                    i--;
                }
                ret.push_back(matrix[i][j]);
                d3++;
                j++;
                direction = 0;
            }
        }
        return ret;
    }
};