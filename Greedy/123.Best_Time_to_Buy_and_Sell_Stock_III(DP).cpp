/*
The most popular solution is following, it is simple, but not easy to understand.
It is kind of DP, but the most important category is greedy.

My interpretation:
1.Some implicit conditions:
  we can buy and sell at the same day twice, it is also two transactions, only the profit is 0.
  For the day before the first day, we assume the profits of first and second are both 0.
2.b1, b2 are amount of money we have after first and second buys,
  s1, s2 are profits we made after first and second sells.
  where are they come from on te i-th day?
  b1: max of buy(-prices[i]) or not(last b1).
  s1: must come after b1, max of sell(b1+prices[i]) or not(last s1).
  b2: must come after s1, max of buy(s1-prices[i]) ors not(last b2).
  s2: must come after b2, max of sell(b2+prices[i]) or not(last s2).

Time: O(n);
Space: O(1).
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int b1=INT_MIN,b2=INT_MIN;
        int s1=0,s2=0;
        for(int i=0;i<prices.size();i++){
            b1=max(b1,-prices[i]);
            s1=max(s1,b1+prices[i]);
            b2=max(b2,s1-prices[i]);
            s2=max(s2,b2+prices[i]);
        }
        return s2;
    }
};

/*
The above solution is classified into DP category.
We didn't implement dp array, because the ith result only depends on the result of last day and previous time of today.

It may be a little more clear by implementing dp array.

Time: O(n);
Space: O(n).
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int> b1(n+1),b2(n+1),s1(n+1),s2(n+1);
        b1[0]=INT_MIN,b2[0]=INT_MIN,s1[0]=0,s2[0]=0;
        for(int i=0;i<n;i++){
            b1[i+1]=max(b1[i],-prices[i]);
            s1[i+1]=max(s1[i],b1[i+1]+prices[i]);
            b2[i+1]=max(b2[i],s1[i+1]-prices[i]);
            s2[i+1]=max(s2[i],b2[i+1]+prices[i]);
        }
        return s2[n];
    }
};
