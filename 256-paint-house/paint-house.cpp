class Solution {
public:
    int minCostPaint(int ind,int prev,vector<vector<int>> &costs){
        if(ind>=costs.size())return 0;
        int cost = INT_MAX;
        for(int i=0;i<3;i++){
            if( prev==-1 || i!=prev){
                cost=min(cost,costs[ind][i]+minCostPaint(ind+1,i,costs));
            }
        }
        return cost;
    }
    int minCost(vector<vector<int>>& costs) {
        // return minCostPaint(0,-1,costs);
        int n = costs.size();
        vector<vector<int>> dp(n+1,vector<int>(4,0));
        for(int i=n-1;i>=0;i--){
            for(int prev=-1;prev<3;prev++){
            int cost = INT_MAX;
            for(int j=0;j<3;j++){
                if(prev==-1 || prev!=j){
                    int x = costs[i][j]+dp[i+1][j+1];
                    cost=min(cost,x);
                }
            }
            dp[i][prev+1]=cost;
                
            }
        }
        //return *min_element(dp[0].begin(),dp[0].end());
        return dp[0][0];


    }
};