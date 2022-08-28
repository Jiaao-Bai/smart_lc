class Solution {
    //第一版朴素/暴力解法，模拟飞行过程一个一个去试
public:
    map<int, map<int, int>> price_map;
    int min_price = INT_MAX;
    int current_price=0;
    vector<bool> already_reach_citys;

    void try_fly(int src, int dst, int k){
        if(k==0){
            if(price_map[src].find(dst)!=price_map[src].end()){
                current_price+=price_map[src][dst];
                min_price = (current_price<min_price)?current_price:min_price;
                current_price-=price_map[src][dst];
            }
            return;
        }


        for(auto& dst_pair:price_map[src]){
            if(dst_pair.first==dst){
                current_price+=price_map[src][dst];
                min_price = (current_price<min_price)?current_price:min_price;
                current_price-=price_map[src][dst];
                continue;                
            }
            if(already_reach_citys[dst_pair.first]!=true){
                already_reach_citys[dst_pair.first]=true;
                current_price += dst_pair.second;
                try_fly(dst_pair.first, dst, k-1);
                already_reach_citys[dst_pair.first]=false;
                current_price -= dst_pair.second;
            }
        }
    }

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        for(auto& v:flights){
            price_map[v[0]][v[1]] = v[2];
        }
        already_reach_citys = vector<bool>(n,false);
        already_reach_citys[src] =  true;
        try_fly(src, dst, k);
        if(min_price==INT_MAX){
            min_price = -1;
        }
        return min_price;
    }
};