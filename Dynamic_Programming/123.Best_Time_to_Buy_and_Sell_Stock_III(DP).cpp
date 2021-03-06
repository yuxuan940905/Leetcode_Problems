/*
Straight forward DP.
dp[k][i] means most profit at i th day at most k transactions.
the  state transition formular is:
dp[k][i]=max{dp[k][i-1],max(prices[i]-prices[j]+dp[k-1][j-1])}, j=[1,2,3...i].
It can be modified to:
dp[k][i]=max{dp[k][i-1],prices[i]-min(prices[j]-dp[k-1][j-1])}, j=[1,2,3...i].
we should also handle the situation where j=0:
we can buy and sell any times within one day, so when j=0, 
the min(prices[j]-dp[k-1][j-1]) becomes prices[0]. means we buy and sell k-1 times at the first day, and then buy prices[0].
That why we start cur_min with prices[0] for every k.
when we loop on prices by i, we can get the min(prices[j]-dp[k-1][j-1]) at the same time.
because j's range here is [1,2,3...i] exactly.

Time: O(k*n);
Space: O(k*n).
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n==0) return 0;
        vector<vector<int>> dp(3,vector<int>(n,0));
        for(int k=1;k<=2;k++){
            int cur_min=prices[0];
            for(int i=1;i<n;i++){
                cur_min=min(cur_min,prices[i]-dp[k-1][i-1]);
                dp[k][i]=max(dp[k][i-1],prices[i]-cur_min);
            }
        }
        return dp[2][n-1];
    }
};