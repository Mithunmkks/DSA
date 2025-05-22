class LRUCache {
public:
    class ListNode{
        public:
        int key;
        int val;
        ListNode* next;
        ListNode* prev;
        ListNode(int key , int val)
        {
            this->key = key;
            this->val = val;
            this->next = NULL;
            this->prev = NULL;
        }
    };
    void insertAtHead(ListNode*&head,ListNode*&node)
    {
        node->next=head->next;
        node->prev=head;
        head->next->prev=node;
        head->next=node;
    }
    void clean(ListNode*&node)
    {
        node->prev->next=node->next;
        node->next->prev=node->prev;
        node->next=NULL;
        node->prev=NULL;
    }
    void deletion(ListNode*&node)
    {
        node->prev->next=tail;
        tail->prev=node->prev;
        node->next=NULL;
        node->prev=NULL;
    }
    
    unordered_map<int,ListNode*>mp;
    int capacity;
    ListNode* head = NULL;
    ListNode* tail = NULL;

    LRUCache(int capacity) {
        head = new ListNode(-1,-1);
        tail = new ListNode(-1,-1);
        head->next = tail;
        tail->prev = head;
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end())
        {
            int r = mp[key]->val;
            clean(mp[key]);
            insertAtHead(head,mp[key]);
            return r;
        }
        else return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end())
        {
            mp[key]->val=value;
            clean(mp[key]);
            insertAtHead(head,mp[key]);
            return ;
        }
        if(capacity<=0)
        {
            ListNode* node = tail->prev;
            deletion(node);
            mp.erase(node->key);
        }
        ListNode* node = new ListNode(key,value);
        ListNode* nextnode = head->next;
        node->next = nextnode;
        head->next = node;
        node->prev=head;
        nextnode->prev = node; 
        mp[key]=node;
        capacity--;

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */