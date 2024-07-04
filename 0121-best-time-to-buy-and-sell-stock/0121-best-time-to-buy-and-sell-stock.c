int maxProfit(int* prices, int pricesSize) {
    int min = prices[0];
    int maxProfit = 0;

    for (int i = 0; i < pricesSize; i++) {
        if (prices[i] < min) {
            min = prices[i];
        }
        
        int profit = prices[i] - min;
        if (profit > maxProfit) {
            maxProfit = profit;
        }
    }
    return maxProfit;
}