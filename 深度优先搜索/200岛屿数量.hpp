//并查集也可以
/*
有bug
class Solution {
public:
    set<int> island_id_set;
    int new_island_id=1;
    vector<vector<int>> internal_grid;
    multimap<int, int> repeat_ids;

    void process(int w, int h){
        if(internal_grid[h][w]==-2){
            internal_grid[h][w] = 0;
            if(h+1<=internal_grid.size()-1 && internal_grid[h+1][w]<0){
                process(h+1, w);
            }
            if(w+1<=internal_grid[0].size()-1 && internal_grid[h][w+1]<0){
                process(h, w+1);
            }
            return;
        }else if(internal_grid[h][w]==-1){
            internal_grid[h][w] = new_island_id;
            island_id_set.insert(new_island_id);
            new_island_id++;
        }
        //本节点是陆地
        if(h+1<=internal_grid.size()-1){
            if(internal_grid[h+1][w]==-2){
                //下个节点不是陆地
                process(h+1, w);
            }else if(internal_grid[h+1][w]==-1){
                //传染
                internal_grid[h+1][w] = internal_grid[h][w];
                process(h+1, w);
            }else if(internal_grid[h+1][w]!=internal_grid[h][w]){
                //已经被处理过，检查是否相等
                repeat_ids.insert({internal_grid[h+1][w], internal_grid[h][w]});
            }
        }

        if(w+1<=internal_grid[0].size()-1){
            if(internal_grid[h][w+1]==-2){
                process(h, w+1);
            }else if(internal_grid[h][w+1]==-1){
                internal_grid[h][w+1] = internal_grid[h][w];
                process(h, w+1);
            }else if(internal_grid[h][w+1]!=internal_grid[h][w]){
                repeat_ids.insert({internal_grid[h][w+1], internal_grid[h][w]});
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int h = grid.size();
        if(h==0){
            return 0;
        }
        int w = grid[0].size();
        if(w==0){
            return 0;
        }
        for(int i=0; i<h; i++){
            vector<int> tmp_vec;
            for(int j=0; j<w; j++){
                int val;
                if(grid[i][j]=='1'){
                    val = -1;
                }else{
                    val = -2;
                }
                tmp_vec.push_back(val);
            }
            internal_grid.push_back(tmp_vec);
        }

        process(0, 0);
        for(auto& p:repeat_ids){
            int low, high;
            if(p.first>p.second){
                low = p.second;
                high = p.first;
            }else{
                low = p.first;
                high = p.second;
            }
            if(island_id_set.find(high)!=island_id_set.end()){
                island_id_set.erase(high);
            }
        }
        return island_id_set.size();
    }
};
*/

class Solution {
public:
    void dfs(vector<vector<char>>& grid, int x, int y){
        grid[y][x]='0';
        if(y-1>=0 && grid[y-1][x]=='1'){
            dfs(grid, x, y-1);
        }
        if(y+1<=grid.size()-1 && grid[y+1][x]=='1'){
            dfs(grid, x, y+1);
        }
        if(x-1>=0 && grid[y][x-1]=='1'){
            dfs(grid, x-1, y);
        }
        if(x+1<=grid[0].size()-1 && grid[y][x+1]=='1'){
            dfs(grid, x+1, y);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        for(int y=0; y<grid.size(); y++){
            for(int x=0; x<grid[0].size(); x++){
                if(grid[y][x]=='1'){
                    dfs(grid, x, y);
                    count++;
                }
            }
        }
        return count;
    }
};