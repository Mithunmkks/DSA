class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        int li = -1;
        vector<int> ans(n,1e9);
        for(int i=0;i<n;i++){
            if(seats[i]==1)li=i;
            if(li!=-1 && i-li<ans[i])ans[i]=i-li;
        }
        li=-1;
        for(int i=n-1;i>=0;i--){
            if(seats[i]==1)li=i;
            if(li!=-1 && li-i<ans[i])ans[i]=li-i;
        }
        return *max_element(ans.begin(),ans.end());
    }
};