class MyStack {
public:

    queue<int>  q2;
    MyStack() {
    }
    void push(int x) {
        queue<int> q1;
        q1.push(x);
        while(!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
        q2=q1;
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