class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0,h=nums.size()-1;
        while(l<=h)
        {
            int mid = l+(h-l)/2;
            if(nums[mid]==target)return mid;
            if(nums[l]<=nums[mid])
            {
                if(nums[l]<=target && nums[mid]>=target)h=mid;
                else l=mid+1;
            }
            else 
            {
                if(nums[mid]<=target && target<=nums[h])
                {
                    l=mid+1;
                }
                else h=mid;
            }
        }
        return -1;

    
    }
};