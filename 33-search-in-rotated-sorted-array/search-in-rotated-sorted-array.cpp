class Solution {
public:
    
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int mid,l=0,h=n-1;
        while(l<h)
        {
            mid=(l+h)/2;
            if(nums[mid]>nums[h])l=mid+1;
            else h=mid;
        }
        int pivot = l;
        l=0,h=pivot-1;
        while(l<=h)
        {
            mid=(l+h)/2;
            if(nums[mid]==target)return mid;
            if(nums[mid]<target)l=mid+1;
            else h=mid-1;
        }
        l=pivot,h=n-1;
        while(l<=h)
        {
            mid=(l+h)/2;
            if(nums[mid]==target)return mid;
            if(nums[mid]<target)l=mid+1;
            else h=mid-1;
        }
        return -1;
        
    }
};


// 56,58,59,100,123,127,198,199,1,2,3,4,5,6,7,8
// [4,5,6,7,0,1,2]
//  0 1 2 3 4 5 6
//.         ..   .