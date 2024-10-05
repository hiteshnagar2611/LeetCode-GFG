class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        // Sort the array first
        sort(nums.begin(), nums.end());
        
        long long total = 0; // Use long long to store the total sum of the current window
        int left = 0;        // Left pointer of the sliding window
        int maxFreq = 1;     // The result to store the maximum frequency
        
        // Iterate with the right pointer
        for (int right = 0; right < nums.size(); right++) {
            // Add nums[right] to the total sum
            total += nums[right];
            
            // Check if the total cost exceeds k (use long long for the multiplication)
            while (static_cast<long long>(nums[right]) * (right - left + 1) > total + k) {
                total -= nums[left]; // Remove nums[left] from the sum
                left++;
            }
            
            // Update the maximum frequency
            maxFreq = max(maxFreq, right - left + 1);
        }
        
        return maxFreq;
    }
};
