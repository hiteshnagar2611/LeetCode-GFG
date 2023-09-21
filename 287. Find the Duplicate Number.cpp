// Without CHANGE ARRAY(best)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            swap(nums[0],nums[nums[0]]);
        }

        return nums[0];
    }
};

///////////////////////////////////////////////////////////////////////////////////////////
// TIME LIMIE EXCIEDD
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int start=0;
        int end=nums.size()-1;

        while(start < end){
                while(end > start){
                    if(nums[start]==nums[end]){
                        return nums[start];
                        break;
                    }
                    else{
                        end--;
                    }
                }
                start++;
                end=nums.size()-1;
        }
        return -1;
    }
};

/////////////////////////////////////////////////////////////////////////////////////////

// WORKING 
// BUT WE CHANGE ARRAY
// T.C.  O(nlog(n)) 
//S.C. O(n)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int first=0;
        int second=1;

        while(second < nums.size() ){
            if(nums[first]==nums[second]){
                return nums[first];
                break;
            }
            else{
                first++;
                second++;
            }
        }

        return -1;

    }
};

/////////////////////////////////////////////////////////////////////////////////////
//NAGATIVE MARKING METHOD
// WORKING 
// BUT WE CHANGE ARRAY
// T.C.  O(nlog(n)) 
//S.C. O(1)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int ans= -1;
        for(int i=0;i<nums.size();i++){
            int index= abs(nums[i]);

            if(nums[index] < 0){
                ans=index;
                break;
            }
            nums[index] *= -1;
        }
        return ans;
    }
};
