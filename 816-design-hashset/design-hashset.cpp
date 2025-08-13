class MyHashSet {
public:
    int M;
    vector<list<int>> buckets;

    MyHashSet() {
        M = 15000;
        buckets = vector<list<int>>(M,list<int>{});
    }
    
    void add(int key) {
        int ind = key%M;
        auto itr = find(buckets[ind].begin(),buckets[ind].end(),key);
        if(itr==buckets[ind].end())buckets[ind].push_back(key);
    }
    
    void remove(int key) {
        int ind = key%M;
        auto itr = find(buckets[ind].begin(),buckets[ind].end(),key);
        if(itr!=buckets[ind].end())buckets[ind].erase(itr);
    }
    
    bool contains(int key) {
        int ind = key%M;
        auto itr = find(buckets[ind].begin(),buckets[ind].end(),key);
        if(itr==buckets[ind].end())return false;
        return true;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */