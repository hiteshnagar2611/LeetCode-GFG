// solution 1
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==0 || n == INT_MIN){
            return false;
        }
        else if((n & (n-1)) == 0 ){
            return true;
        }
        else{
            return false;
        }
        
    }
};

// solution 2
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) {
            return false;
        }
        return (n & (n - 1)) == 0;
    }
};

// solution 3
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }
};
