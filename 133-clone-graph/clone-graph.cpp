class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node)return node;
        if(node->neighbors.size()==0)return new Node(node->val);
        set<Node*> vis;
        map<Node*,Node*> mp;
        queue<Node*> q;
        q.push(node);
        mp[node]=new Node(node->val);
        while(!q.empty())
        {
            auto node = q.front();
            q.pop();
            vis.insert(node);
            for(auto &adjnode:node->neighbors)
            {
                if(vis.find(adjnode)==vis.end())
                {
                    mp[adjnode]=new Node(adjnode->val);
                    q.push(adjnode);
                }
            } 
        }
        vis.clear();
        q.push(node);
        vis.insert(node);
        while(!q.empty())
        {
            auto node = q.front();
            q.pop();
            for(auto &adjnode:node->neighbors)
            {
                mp[node]->neighbors.push_back(mp[adjnode]);
                if(vis.find(adjnode)==vis.end()){
                vis.insert(adjnode);
                q.push(adjnode);
                }   
            }
        }
        return mp[node];
        
    }
};