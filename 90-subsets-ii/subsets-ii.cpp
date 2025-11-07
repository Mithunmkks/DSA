class Solution {
public:
    void f(int ind ,vector<int> &temp, vector<int> &nums,vector<vector<int>>&ds)
    {
       
        ds.push_back(temp);
            
        
        for(int i=ind;i<nums.size();i++){
            if(i!=ind && nums[i-1]==nums[i])continue;
            temp.push_back(nums[i]);
            f(i+1,temp,nums,ds);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        sort(nums.begin(),nums.end());
        vector<vector<int>> ds;
        f(0,temp,nums,ds);
        return ds;
    }
};