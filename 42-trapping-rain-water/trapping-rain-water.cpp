class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> l(n,0),r(n,0);
        l[0]=height[0];
        r[n-1]=height[n-1];
        for(int i=1;i<n;i++)l[i]=max(height[i],l[i-1]);
        for(int j=n-2;j>=0;j--)r[j]=max(height[j],r[j+1]);
        int ans=0;
        for(int i=1;i<n-1;i++)
        {
            int h = min(l[i],r[i]);
            if(h-height[i]>0)ans+=h-height[i];
        }
        for(auto &i:l)cout<<i<<" ";cout<<endl;
        for(auto &i:r)cout<<i<<" ";cout<<endl;
        return ans;

    }
};