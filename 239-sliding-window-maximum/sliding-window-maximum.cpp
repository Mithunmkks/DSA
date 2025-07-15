class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> d;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {

            while (!d.empty() && nums[i] >= nums[d.back()])
                d.pop_back();

            while (!d.empty() && (d.front()<=i-k) )
                d.pop_front();

            d.push_back(i);


            if (i >= k - 1) {
                ans.push_back(nums[d.front()]);
            }
        }
        return ans;
    }
};