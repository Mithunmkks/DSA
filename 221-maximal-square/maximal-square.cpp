class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n,vector<int>(m,0));
        int ans = 0;
        for(int i= n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(matrix[i][j]=='1'){
                    int right = 0;
                    if(j+1<m)right = dp[i][j+1];
                    int diag = 0;
                    if(i+1<n && j+1<m)diag=dp[i+1][j+1];
                    int down = 0;
                    if(i+1<n)down=dp[i+1][j];
                    dp[i][j]=1+min({right,down,diag});
                    ans=max(ans,dp[i][j]);
                }
            }
        }
        return ans*ans;


    }
};