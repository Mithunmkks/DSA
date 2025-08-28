class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        bool needEven = true;
        int len = 0;
        int curlen = 0;
        for(int i=0;i<nums.size();i++){
            if(needEven && nums[i]%2==0 && nums[i]<=threshold){
                curlen++;
                len=max(len,curlen);
                needEven=false;
            }else if (!needEven && nums[i]%2==1 && nums[i]<=threshold){
                curlen++;
                len=max(len,curlen);
                needEven=true;
            }
            else {
                curlen=0;
                needEven=true;
                if(nums[i]%2==0 && nums[i]<=threshold){
                    curlen++;
                    needEven=false;
                    len=max(len,curlen);
                }
            }
        }
        return len;
        
    }
};