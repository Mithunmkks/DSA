class Solution {
public:
    int merge(int low,int high,int mid,vector<int>&nums)
    {
        vector<int> temp;
        int count=0;
        int j=mid+1;
        for(int i=low;i<=mid;i++)
        {  
            while(j<=high && nums[i]>2ll*nums[j])j++;
            count+=j-(mid+1);
        }
        int i=low;
        j=mid+1;
        while(i<=mid && j<=high)
        {
            if(nums[i]<=nums[j])
            {
                temp.push_back(nums[i]);
                i++;
            }
            else 
            {
                temp.push_back(nums[j]);
                j++;
            }
        }
        while(i<=mid)temp.push_back(nums[i++]);
        while(j<=high)temp.push_back(nums[j++]);
        for(int i=low;i<=high;i++)nums[i]=temp[i-low];
        return count;
    }
    int mergesort(int i,int j,vector<int> &nums)
    {
        int ans=0;
        if(i<j)
        {
            int mid = (i+j)/2;
            ans+=mergesort(i,mid,nums);
            ans+=mergesort(mid+1,j,nums);
            ans+=merge(i,j,mid,nums);
        }
        return ans;
    }
    int reversePairs(vector<int>& nums) {
        return mergesort(0,nums.size()-1,nums);
    }
};