#include "header.hpp"
//代码看着没啥问题 就是会越界
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row_size = grid.size();
        if(row_size==0){
            return 0;
        }
        int col_size = grid[0].size();
        if(col_size==0){
            return 0;
        }
        vector<vector<int>> cache(row_size, vector<int>(col_size));
        cache[0][0] = grid[0][0];
        for(int i=1; i<col_size; i++){
            cache[0][i] = cache[0][i-1] + grid[0][i];
        }
        for(int i=1; i<row_size; i++){
            cache[i][0] = cache[i-1][0] + grid[i][0];
        }

        for(int i=1; i<row_size; i++){
            for(int j=1; j<col_size; j++){
                cache[i][j] = std::min({cache[i-1][j], cache[i][j-1]}) + grid[i][j];
            }
        }

        return cache[row_size-1][col_size-1];
    }
};