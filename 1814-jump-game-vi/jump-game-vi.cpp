class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        deque<pair<int,int>> dq;
        // score,index
        dq.push_back({nums[n-1],n-1});
        int score = nums[0];
        for(int i=n-2;i>=0;i--){
            while(!dq.empty() && dq.front().second>i+k)dq.pop_front();
            score = nums[i]+dq.front().first;
            while(!dq.empty() && dq.back().first<=score)dq.pop_back();
            dq.push_back({score,i});
        }
        return score;
        
    }
};