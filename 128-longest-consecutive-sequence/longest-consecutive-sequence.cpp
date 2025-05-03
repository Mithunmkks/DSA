class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());


        int n= nums.size();
        int maxi=0;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(cnt==0)
            {
                cnt++;
                maxi=max(cnt,maxi);
             }
            else if (i>0 && nums[i]==nums[i-1]+1)
            {
                cnt++;
                maxi=max(maxi,cnt);
             }
            else if(i>0 && nums[i]==nums[i-1])
            {

               
            }
            else
            {
               cnt=1;
           }
            


        }
        return maxi;

       

    }
};

// 1 2 3 4 100 200 