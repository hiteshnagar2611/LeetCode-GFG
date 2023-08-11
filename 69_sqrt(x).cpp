// solution 1
class Solution {
public:
    int mySqrt(int x) {
        long long y=0;
        while((y*y)<=x){
            y++;
        }
        return y-1;
    }
};


// solution 2
class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) {
            return 1.0;
        }
        
        double half = myPow(x, n / 2);
        
        if (n % 2 == 0) {
            return half * half;
        } else if (n > 0) {
            return x * half * half;
        } else {
            return (1 / x) * half * half;
        }
    }
};
