class Solution {
public:
    int ans=INT_MAX;
    void f(int ind,vector<int> &cookies,vector<int>&dist){
        if(ind>=cookies.size()){

            ans=min(ans,*max_element(dist.begin(),dist.end()));
            
            return;
        }
        for(int i=0;i<dist.size();i++){
            dist[i]+=cookies[ind];
            f(ind+1,cookies,dist);
            dist[i]-=cookies[ind];
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> dist(k,0);
        f(0,cookies,dist);
        return ans;
    }
};