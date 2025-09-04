class Solution {
public:
    static bool mycomp(pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    }
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int, int>> vec;
        for (int i = 0; i < n; i++) {
            vec.push_back({nums1[i], nums2[i]});
        }
        sort(vec.begin(), vec.end(), mycomp);
        for (int i = 0; i < n; i++) {
            nums1[i] = vec[i].first;
            nums2[i] = vec[i].second;
        }
        long long  ans = 0;
        priority_queue<int,vector<int>,greater<int>> pq;
        for(auto c:nums1)cout<<c<<" ";
        cout<<endl;
        for(auto c:nums2)cout<<c<<" ";
        long long sum = 0;
        for(int i=0;i<k;i++){
            sum += nums1[i];
            pq.push(nums1[i]);
        }
        ans = max(ans,sum*nums2[k-1]);
        for (int i = k; i < n; i++) {
            pq.push(nums1[i]);
            sum+=nums1[i];
            int x = pq.top();
            sum-=x;
            pq.pop();
            ans=max(ans,sum*nums2[i]);
        }
        return ans;
    }
};