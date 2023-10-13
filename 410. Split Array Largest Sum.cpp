class Solution {
public:

    bool isPossible(vector<int>& nums,int N,int M,int sol){
        int pageSum = 0;
        int studentCount = 1;
        for(int i = 0;i < N;i++){
            // Number of pages is itself greater than solution 
            if(nums[i] > sol){
                return false;
            }
            if(pageSum + nums[i] > sol){
                studentCount++;
                pageSum = nums[i];
                if(studentCount>M){
                    return false;
                }
            }
            else{
                    pageSum = pageSum + nums[i];
                }
        }
        return true;
    }

    int splitArray(vector<int>& nums, int k) {
        int N = nums.size();
        int M=k;
        if(M > N){
            return -1;
        }
        int start = 0;
        int end = accumulate(nums.begin(),nums.end(),0);
        int ans = -1;
        while(start<=end){
            // Find mid
            int mid = start + (end-start)/2;
            if(isPossible(nums,N,M,mid)){
                // Store answer
                ans = mid;
                // Explore minimum 
                end = mid - 1;
            }
            else{
                // Not possible
                start = mid + 1;
            }
        }
        return ans;
    }
};
