class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int total_profit = 0;
        int buy_price=-1;
        if(prices.size()<=1){
            return 0;
        }

        for(auto i=prices.begin(); i!=prices.end()-1; i++){
            if(*(i+1)<=*i){
                if(buy_price!=-1){
                    int profit = *i - buy_price;
                    total_profit += profit;
                    buy_price = -1;
                }
            }else{
                if(buy_price==-1){
                    buy_price = *i;
                }
            }
        }

        if(buy_price!=-1){
            int profit = prices.back() - buy_price;
            total_profit += profit;
        }

        return total_profit;
    }
};