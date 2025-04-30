class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini=prices[0];
        int x=0;
        int n=prices.size();
        for(int i=1;i<n;i++)
        {
            x=max(x,prices[i]-mini);
            mini=min(mini,prices[i]);
        }
        return x;

    }
};