class Solution {
public:
    int dp[201][201],n,m;
    int dfs(int row,int col,vector<vector<int>>& matrix){
        if(dp[row][col]!=-1)return dp[row][col];
        int delrow[]={1,-1,0,0};
        int delcol[]={0,0,1,-1};
        int len =0;
        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && matrix[nrow][ncol]>matrix[row][col]){
                len = max(len,dfs(nrow,ncol,matrix));
            }
        }
        return dp[row][col]=len+1;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        memset(dp,-1,sizeof(dp));
        n = matrix.size();
        m = matrix[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                ans=max(ans,dfs(i,j,matrix));
            }
        }
        return ans;

    }
};