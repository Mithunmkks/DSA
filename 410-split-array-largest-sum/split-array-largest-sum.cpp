class Solution {
public:
    bool check(int sum , int k , vector<int> &nums){
        int parts = 1;
        int curSum = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>sum)return false;
            if(curSum+nums[i]<=sum)curSum+=nums[i];
            else {
                curSum = nums[i];
                parts++;
            }
        }
        return parts<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        int l = *min_element(nums.begin(),nums.end());
        int h = accumulate(nums.begin(),nums.end(),0);
        int ans = *max_element(nums.begin(),nums.end());
        while(l<=h){
            int mid = l+(h-l)/2;
            cout<<mid<<' ';
            cout<<check(mid,k,nums)<<" || ";
            if(check(mid,k,nums)==true){
                ans=mid;
                h=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};