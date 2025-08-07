class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int mindiff = INT_MAX;
        int ans = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            int l = i + 1;
            int h = nums.size() - 1;

            while (l < h) {
                int curSum = nums[i] + nums[l] + nums[h];
                int diff = abs(curSum - target);

                if (diff < mindiff) {
                    mindiff = diff;
                    ans = curSum;
                }

                if (curSum < target) {
                    l++;
                } else if (curSum > target) {
                    h--;
                } else {
                    return target; // Exact match found
                }
            }
        }

        return ans;
    }
};
