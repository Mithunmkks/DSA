class Solution {
public:
    int maxSum(vector<int>& nums) {
        vector<int> freq(101,0);
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                freq[nums[i]]=1;
            }
        }
        int sum =0;
        for(int i=0;i<freq.size();i++){
            if(freq[i]){
            sum+=i;
            cout<<i<<" ";
            }
        }
        if(sum==0){
            return *max_element(nums.begin(),nums.end());
        }
        return sum;
    }
};