class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int last1=m-1;
        int last2=n-1;
        int lastmerg=m+n-1;

        while(last2 >= 0){
            if(last1 >=0 && nums1[last1] > nums2[last2]){
                nums1[lastmerg--]=nums1[last1--];
            }
            else{
                nums1[lastmerg--]=nums2[last2--];
            }
        }
    }
};
