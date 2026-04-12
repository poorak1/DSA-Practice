class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int curr_min = prices[0];
        int max_profit = 0;
        for(int &price: prices){
            int curr_profit = price - curr_min;
            max_profit = max(max_profit, curr_profit);
            curr_min = min(curr_min, price);
        }

        return max_profit;
    }
};