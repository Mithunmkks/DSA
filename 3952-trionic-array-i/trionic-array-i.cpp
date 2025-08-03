class Solution {
public:
    bool isTrionic(vector<int>& nums) {

        int i=0;
        int ctr=0;
        int n = nums.size();

        while(i+1<n){
            if(ctr>2){
                return 0;
            }
            if(ctr>i){
                return 0;
            }
            if(ctr%2==0){
                if(nums[i+1]>nums[i]){
                    i++;
                }
                else{
                    ctr++;
                }
            }
            else{
                if(nums[i]>nums[i+1]){
                    i++;
                }
                else{
                    ctr++;
                }
            }
        }
        cout<<ctr<<endl;
        if(nums[n-2]>nums[n-1]||ctr<2) return 0;
        return 1;
    }
};