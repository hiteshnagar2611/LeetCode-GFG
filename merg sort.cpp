class Solution {
public:

    void merge(vector<int> &nums, int s, int e){
        int mid = (s+e)/2;

        int len1 = mid-s+1;
        int len2 = e-mid;

        int *first = new int[len1];
        int *second = new int[len2];

        // copy values
        int k =s;

        for(int i=0; i<len1; i++){
            first[i] = nums[k++];
        }

        k = mid+1;
        for(int j=0; j<len2; j++){
            second[j] = nums[k++];
        }

        //merge 2 sorted arrays

        int index1 = 0;
        int index2 = 0;
        int mainarrindex = s;
        while(index1 < len1 && index2 < len2){
            if(first[index1] < second[index2]){
                nums[mainarrindex++] = first[index1++];
            }
            else{
                nums[mainarrindex++] = second[index2++];
            }
        }

        while(index1 < len1){
            nums[mainarrindex++] = first[index1++];
        }

        while(index2 < len2){
            nums[mainarrindex++] = second[index2++];            
        }
    }

    void mergesort(vector<int> &nums, int s, int e){
        int mid = (s+e)/2;

        if(s>=e){
            return ;
        }

        // sort left side
        mergesort(nums, s, mid);

        // sort right side
        mergesort(nums, mid+1, e);

        //merge both arrays

        merge(nums, s, e);
    }

    vector<int> sortArray(vector<int>& nums) {
        int s = 0;
        int e = nums.size()-1;

        mergesort(nums, s, e);

        return nums;
    }
};
