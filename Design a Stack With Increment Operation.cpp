class CustomStack {
public:
    int top;
    int *arr;
    int size;
    CustomStack(int maxSize) {
        this->size = maxSize;
        arr = new int[size];
        top = -1;
    }
    
    void push(int x) {
        if(top == size -1){
            return ;
        }
        else{
            top++;
            arr[top] = x;
        }
    }
    
    int pop() {
        if(top == -1){
            return -1;
        }
        else{
            int temp = arr[top];
            top--;
            return temp;
        }
    }
    
    void increment(int k, int val) {
        int limit = min(k, size);
        for(int i=0; i< limit; i++){
            arr[i] = arr[i]+val;
        }
    }
};
