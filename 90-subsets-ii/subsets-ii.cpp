class Solution {
public:
    vector<vector<int>> ans;
    void f(int ind,vector<int> &temp,vector<int> &nums)
    {

            ans.push_back(temp);

        for(int i=ind;i<nums.size();i++)
        {
            if(i==ind || nums[i]!=nums[i-1]){
            temp.push_back(nums[i]);
            f(i+1,temp,nums);
            temp.pop_back();
            }
        }

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        sort(nums.begin(),nums.end());
        f(0,temp,nums);
        return ans;
    }
};