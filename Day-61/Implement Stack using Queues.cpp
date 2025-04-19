class MyStack {
public:
queue<int>q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        int v=q.size()-1;
        int i=0;
        while(i<v){
          q.push(q.front());
          i++;
          q.pop();
        }
    }
    
    int pop() {
        int p=q.front();
        q.pop();
        return p;
    }
    
    int top() {
      return q.front();  
    }
    
    bool empty() {
        return q.size()==0;
    }
};
