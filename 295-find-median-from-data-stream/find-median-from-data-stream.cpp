class MedianFinder {
public:
    priority_queue<int> maxheap;
    priority_queue<int,vector<int>,greater<int>> minheap;
    MedianFinder() {
        
    } 
    void addNum(int num) {
        if(!minheap.empty() && num>minheap.top())
        {
            minheap.push(num);
        }
        else 
        {
            maxheap.push(num);
        }

        if(maxheap.size()>minheap.size()+1)
        {
            minheap.push(maxheap.top());
            maxheap.pop();
        }
        else if (minheap.size()>maxheap.size())
        {
            maxheap.push(minheap.top());
            minheap.pop();
        } 
    }   
    double findMedian() {
        if(minheap.size()==maxheap.size())return (minheap.top()+maxheap.top())/2.0;
        else return maxheap.top()/1.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
