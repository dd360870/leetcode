#include <stdio.h>
#include <stdlib.h>


int maxProfit(int* prices, int pricesSize){
    if (pricesSize == 0 || pricesSize == 1) {
        return 0;
    }
    int profit = 0;
    int curr_profit = 0;
    for (int i=1;i<pricesSize; i++) {
        int diff = prices[i] - prices[i-1];
        if (diff > 0) {
            curr_profit += diff;
        }
        else if (diff < 0) {
            profit += curr_profit;
            curr_profit = 0;
        }
    }    
    return profit + curr_profit;
}

int main(void) {

}