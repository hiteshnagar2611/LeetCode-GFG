class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> remainder_count(k, 0);

        // Count the remainders when elements are divided by k
        for(int num : arr) {
            int remainder = ((num % k) + k) % k;  // Handle negative numbers
            remainder_count[remainder]++;
        }

        // Check remainder 0
        if(remainder_count[0] % 2 != 0) return false;  // Elements divisible by k must pair with each other

        // Check other remainders
        for(int i = 1; i <= k / 2; i++) {
            if(remainder_count[i] != remainder_count[k - i]) {
                return false;  // The count of remainder i must match the count of remainder k - i
            }
        }

        return true;
    }
};
