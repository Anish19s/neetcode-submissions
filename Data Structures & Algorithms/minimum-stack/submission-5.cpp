class MinStack {
    long min;
    std::stack<long>st;

public:
    
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            st.push(0);
            min=val;
        }
        else{
            st.push(val-min);
            if(val<min){
                min=val;
            }
        }
    }
    
    void pop() {
        long pop=st.top();
        st.pop();
         
        if(pop<0){
            min=min-pop;
        }
    }
    
    int top() {
       long top=st.top();
       return (top>0)?top+min:min;
    }

    int getMin() {
        return (int)min;   
    }
};



