class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()){
            return 0;
        }
        int lowest_price = prices[0];
        int max_profit = -1;
        for(auto& p: prices){
            if(p>=lowest_price){
                auto tmp_profit = p-lowest_price;
                if(tmp_profit>max_profit){
                    max_profit = tmp_profit;
                }
            }else{
                lowest_price = p;
            }
        }
        return max_profit;
    }
};