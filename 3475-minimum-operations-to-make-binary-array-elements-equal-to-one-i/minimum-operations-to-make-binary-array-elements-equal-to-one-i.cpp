class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int countZero =0 , countOne = 0 ;
        int operations  = 0;
        for(int i=0;i<=n-3;i++)
        {
            if(nums[i]==0)
            {
                operations++;
                cout<<"test"<<operations<<endl;
                nums[i]=1-nums[i];
                nums[i+1]=1-nums[i+1];
                nums[i+2]=1-nums[i+2];
            }
        }
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)return -1;
        }
        
        return operations;




        
    }
};