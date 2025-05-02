class Solution {
public:

    int majorityElement(vector<int>& nums) {
        int element = INT_MIN;
        int count =0;
        for(int i=0;i<nums.size();i++)
        {
            if(count==0 || element==nums[i])
            {
                element=nums[i];
                count++;
            }
            else count--;
        }
        return element;

    }
};



