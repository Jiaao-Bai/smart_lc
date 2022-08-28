class Solution {
public:
    int size_ = 0;
    void dfs(vector<vector<int>>& grid, int i, int j){
        size_++;
        grid[i][j] = 0;
        if(i-1>=0 && grid[i-1][j]==1){
            dfs(grid, i-1, j);
        }
        if(j-1>=0 && grid[i][j-1]==1){
            dfs(grid, i, j-1);
        }
        if(i+1<grid.size() && grid[i+1][j]==1){
            dfs(grid, i+1, j);
        }
        if(j+1<grid[0].size() && grid[i][j+1]==1){
            dfs(grid, i, j+1);
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]==1){
                    size_ = 0;
                    dfs(grid, i, j);
                    max = size_>max?size_:max;
                }
            }
        }
        return max;
    }
};