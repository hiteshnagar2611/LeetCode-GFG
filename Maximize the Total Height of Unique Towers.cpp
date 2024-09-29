class Solution {
public:
    long long maximumTotalSum(vector<int>& maximumHeight) {
        // Sort the heights in ascending order
    sort(maximumHeight.begin(), maximumHeight.end());
    
    long long  totalSum = 0;
    int n = maximumHeight.size();
    
    int prevHeight = maximumHeight[n - 1] + 1;  // Start with a value greater than the largest element
    
    // Iterate backwards through the sorted maximum heights
    for (int i = n - 1; i >= 0; --i) {
        // Assign the maximum possible height that is less than the previous one
        prevHeight = min(prevHeight - 1, maximumHeight[i]);
        if (prevHeight <= 0) {
            return -1;  // Impossible to assign unique heights
        }
        totalSum += prevHeight;
    }
    
    return totalSum;
    }
};
