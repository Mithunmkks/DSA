class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans =INT_MIN;
        int cur =1;
        for(auto i:nums){
            if(i!=0){
            cur*=i;
            ans=max(cur,ans);
            }
            else {
            cur=1;
            }
        }
        reverse(nums.begin(),nums.end());
        cur=1;
        for(auto i:nums){
            if(i!=0){
            cur*=i;
            ans=max(cur,ans);
            }
            else {
            cur=1;
            }
        }
        bool flag = false;
        int x=*max_element(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0)flag=true;
        }
        return max(x,ans);
        
    }
};