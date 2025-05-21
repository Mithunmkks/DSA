class MyStack {
public:

    queue<int>  q2;
    MyStack() {
    }
    void push(int x) {
        q2.push(x);
        for(int i=0;i<q2.size()-1;i++)
        {
            q2.push(q2.front());
            q2.pop();
        }
    }   
    int pop() {       
       int x = q2.front();
       q2.pop();
       return x;
    } 
    int top() {
        return q2.front();
    }   
    bool empty() {
        return q2.empty();
    }
};