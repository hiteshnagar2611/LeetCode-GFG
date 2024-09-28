

class twoStacks {
    int *arr;
    int top1;
    int top2;
    int size;
  public:

    twoStacks() {
        size=1000;
        arr = new int[size];
        top1 = -1;
        top2 = size;
        
    }

    // Function to push an integer into the stack1.
    void push1(int x) {
        if(top2-top1 > 1){
            top1++;
            arr[top1] = x;
        }
        else{
            cout<<"stack Overflow";
        }
    }

    // Function to push an integer into the stack2.
    void push2(int x) {
        if(top2-top1 > 1){
            top2--;
            arr[top2] = x;
        }
        else{
            cout<<"stack Overflow";
        }
    }

    // Function to remove an element from top of the stack1.
    int pop1() {
        if(top1 >= 0){
            int res = arr[top1];
            top1--;
            return res;
            
        }
        else{
            return -1;
        }
    }

    // Function to remove an element from top of the stack2.
    int pop2() {
        if(top2 >= size){
            return -1;
        }
        else{
            int res = arr[top2];
            top2++;
            return res;
            
            
        }
    }
};
