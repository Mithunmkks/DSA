class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int i=0,n=nums.size(),last=nums[n-1];
        
        for(int j=0;j<n-1;j++){
            if(nums[j]!=nums[j+1]){
                nums[i]=nums[j];
                i++;
            }
        }

        nums[i]=last;        
        return i+1;
        
    }
};


// 0,0,1,1,1,2,2,3,3,4
// i   j
// 0 0 1 1,1,2,2,3,3,4
//   i j 