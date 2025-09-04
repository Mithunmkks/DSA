class Solution {
public:
    bool  dfs(string node, string tar, double temp, double& val,
             map<string, vector<pair<string, double>>>& mp, set<string>& vis) {
        if (node == tar) {
            val = temp;
            return true;
        }
        vis.insert(node);
        for (auto it : mp[node]) {
            string adjnode = it.first;
            double w = it.second;
            if (vis.find(adjnode) == vis.end()) {
                if(dfs(adjnode, tar, temp*w, val, mp, vis)==true)return true;
            }
        }
        return false;
    }
    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {
        map<string, vector<pair<string, double>>> mp;
        int n = values.size();
        for (int i = 0; i < n; i++) {
            string u = equations[i][0];
            string v = equations[i][1];
            double w = values[i];
            mp[u].push_back({v, w});
            mp[v].push_back({u, 1.0 / w});
        }
        vector<double> ans;
        for (int i = 0; i < queries.size(); i++) {
            string src = queries[i][0];
            string tar = queries[i][1];
            if (mp.count(src) == 0 || mp.count(tar) == 0) {
                ans.push_back(-1.0);
            } else if (src == tar) {
                ans.push_back(1.0);
            } else {
                set<string> vis;
                double val = 0.0;
                if(dfs(src, tar, 1.0, val, mp, vis)==true){
                ans.push_back(val);
                }else {
                    ans.push_back(-1.0);
                }
            }
        }
        return ans;
    }
};