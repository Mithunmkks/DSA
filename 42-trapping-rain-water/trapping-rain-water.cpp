class Solution {
public:
    int trap(vector<int>& height) {
        int  n  = height.size();
        vector<int> pge(n,0),nge(n,0);
        int prev = height[0];
        for(int i=1;i<n;i++){
            pge[i]=prev;
            prev=max(prev,height[i]);
        }
        int next = height[n-1];
        for(int i=n-2;i>=0;i--){
            nge[i]=next;
            next=max(next,height[i]);
        }
        int totalWater = 0;
        for(int i=0;i<n;i++){
            int water = min(pge[i],nge[i])-height[i];
            cout<<water<<" ";
            if(water>0)
            totalWater+=water;
        }
        return totalWater;
        
    }
};