class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0;   // To store the bits that appeared once
        int twos = 0;   // To store the bits that appeared twice
        
        for (int num : nums) {
            ones = (ones ^ num) & ~twos;
            twos = (twos ^ num) & ~ones;
        }
        
        return ones;
    }
};
