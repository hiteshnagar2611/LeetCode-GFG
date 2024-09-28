class Solution{
public:

    void solve(stack<int>& st, int x, int size) {
        if (size < 0) {
            st.push(x);  // Base case: push x when stack is empty
            return;
        }
        
        // Store the top element and remove it
        int topElem = st.top();
        st.pop();
        
        // Recursive call to insert x at the bottom
        solve(st, x, size-1);
        
        // Push the stored top element back
        st.push(topElem);
    }

    stack<int> insertAtBottom(stack<int> st, int x) {
        int size = st.size()-1;
        solve(st, x, size);  // Insert x at the bottom
        return st;  // Return the modified stack
    }
};
