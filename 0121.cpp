class Solution {
public:
    int low;
    int high;
    
    int maxProfit(vector<int>& prices) {
        low = prices[0];
        high = 0;
        
        for(int i=0; i<prices.size(); i++) {

            low = min(prices[i], low);
            high = max(prices[i] - low, high);
        }
        
        return high;
    }
};