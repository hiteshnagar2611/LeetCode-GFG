class Solution {
public:
int digitSum(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;  // Add last digit
        n /= 10;        // Remove last digit
    }
    return sum;
}
    int minElement(vector<int>& nums) {
        int minElement = INT_MAX; // Initialize with a large value
    for (int num : nums) {
        int sum = digitSum(num);
        minElement = std::min(minElement, sum); // Find the minimum digit sum
    }
    return minElement;
    }
};
