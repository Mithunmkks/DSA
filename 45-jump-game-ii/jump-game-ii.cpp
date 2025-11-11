class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n<=1)return 0;
        int farthest=0;
        int current = 0;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            farthest=max(farthest,i+nums[i]);
            if(i==current){
                cnt++;
                current=farthest;
            }
            if(current>=nums.size()-1)break;
        }
        return cnt;
    }
};