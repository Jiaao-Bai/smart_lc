class Solution {
public:
    int size=0;
    void p(vector<vector<int>>& grid, int i, int j){
        //std::cout<<"i: "<<i<<"j: "<<j<<std::endl;
        if(grid[i][j]==1){
            grid[i][j]=3;
            int edge=4;
            if(i-1>=0 && grid[i-1][j]%2==1){
                edge--;
            }
            if(j-1>=0 && grid[i][j-1]%2==1){
                edge--;
            }
            if(i+1<grid.size() && grid[i+1][j]%2==1){
                edge--;
            }
            if(j+1<grid[0].size() && grid[i][j+1]%2==1){
                edge--;
            }
            size+=edge;
        }else{
            grid[i][j]=2;
        }
        if(i-1>=0 && grid[i-1][j]<=1){
            p(grid, i-1, j);
        }
        if(j-1>=0 && grid[i][j-1]<=1){
            p(grid, i, j-1);
        }
        if(i+1<grid.size() && grid[i+1][j]<=1){
            p(grid, i+1, j);
        }
        if(j+1<grid[0].size() && grid[i][j+1]<=1){
            p(grid, i, j+1);
        }
        return;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        p(grid, 0, 0);
        return size;
    }
};