class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        for(int i=1; i< n; i++){
            int temp = nums[i];
            int j=i-1;
            for(; j>=0; j--){
                if(nums[j] > temp){
                    nums[j+1] = nums[j];
                }
                else{
                    break;
                }
            }
            nums[j+1] = temp;
        }

        return nums;
    }
};
