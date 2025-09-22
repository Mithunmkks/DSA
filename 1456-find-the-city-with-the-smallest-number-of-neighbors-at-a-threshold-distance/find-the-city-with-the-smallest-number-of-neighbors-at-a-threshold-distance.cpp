class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n,vector<int>(n,1e8));
        for(int i=0;i<n;i++)dist[i][i]=0;
        for(auto edge:edges){
            int u = edge[0];
            int v = edge[1];
            int d = edge[2];
            dist[u][v]=d;
            dist[v][u]=d;
        }

        for(int via = 0;via<n;via++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    dist[i][j]=min({dist[i][j],dist[i][via]+dist[via][j]});
                }
            }
        }
        vector<int> kdist(n,0);
        for(int i=0;i<n;i++){
            int cnt = 0;
            for(int j=0;j<n;j++){
                if(dist[i][j]<=distanceThreshold)cnt++;
            }
            kdist[i]=cnt;
        }
        int mini = 1e8;
        int miniInd;
        for(int i=0;i<n;i++){
            if(kdist[i]<=mini){
                mini=kdist[i];
                miniInd=i;
            }
        }
        return miniInd;





    }
};