#include <vector>
#include <string>
#include <algorithm>
#include <bitset>

using namespace std;

class Solution {
public:
    // Helper function to concatenate binary representations of numbers
    int binaryConcatenation(const vector<int>& nums) {
        string binaryConcat = "";
        
        // Convert each number to binary and concatenate the result
        for (int num : nums) {
            binaryConcat += bitset<7>(num).to_string().substr(bitset<7>(num).to_string().find('1')); // Remove leading zeros
        }

        // Convert the concatenated binary string to an integer (base 2)
        return stoi(binaryConcat, nullptr, 2);
    }

    // Main function to find the maximum possible number by binary concatenation
    int maxGoodNumber(vector<int>& nums) {
        int maxNumber = 0;

        // Sort the array to generate permutations
        sort(nums.begin(), nums.end());
        
        // Generate all permutations of nums
        do {
            // Calculate the number for the current permutation
            int current = binaryConcatenation(nums);
            
            // Update the maximum number
            maxNumber = max(maxNumber, current);
        } while (next_permutation(nums.begin(), nums.end()));

        return maxNumber;
    }
};
