// using three pointer aproch it short in place

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int start=0;
        int mid=0;
        int end=nums.size()-1;

        while(mid <= end){
            if(nums[mid]==0){
                swap(nums[start],nums[mid]);
                mid++;
                start++;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else{
                swap(nums[mid],nums[end]);
                end--;
            }
        }
    }
};


// using counting aproch but this is not short in place 

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count0,count1,count2;
        count0=count1=count2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                count0++;
            }
            else if(nums[i]==1){
                count1++;
            }
            else{
                count2++;
            }
        }

        int i=0;
        while(count0--){
            nums[i]=0;
            i++;
        }
        while(count1--){
            nums[i]=1;
            i++;
        }
        while(count2--){
            nums[i]=2;
            i++;
        }
    }
};


