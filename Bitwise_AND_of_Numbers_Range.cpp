class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int shift = 0;

        // Find the common leftmost bits in both left and right.
        while (left < right) {
            left >>= 1;
            right >>= 1;
            shift++;
        }

        return left << shift;
    }
};
