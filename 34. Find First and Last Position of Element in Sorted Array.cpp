class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first=0;
        int last=nums.size()-1;

        vector<int> v(2,-1);

        int mid=first+((last-first)/2);

        while(first<=last){
            if(target==nums[mid]){
                int start=mid;
                int end=mid;

                while (start > 0 && nums[start - 1] == target) {
                    start--;
                }

                while (end < nums.size() - 1 && nums[end + 1] == target) {
                    end++;
                }

                v[0]=start;
                v[1]=end;
                break;
                
            }
            else if(target > nums[mid]){
                first=mid+1;
            }
            else{
                last=mid-1;
            }
            mid=first+((last-first)/2);

        }

        return v;

    }
};
