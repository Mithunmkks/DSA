class Solution {
public:
    void sortColors(vector<int>& nums) {
        int a=0,b=0,c=0;
        for(auto &i:nums)
        {
            if(i==0)a++;
            if(i==1)b++;
            if(i==2)c++;
        }
        cout<<a<<" "<<b<<" "<<c<<" ";
        for(int i=0;i<nums.size();i++)
        {
            if(a-- >0)
            {
                nums[i]=0;
                continue;
            }
            if(b-- >0 )
            {
                nums[i]=1;
                continue;
            }
            else nums[i]=2;
        }
    }
};