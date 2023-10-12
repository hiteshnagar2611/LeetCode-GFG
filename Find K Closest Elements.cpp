//sliding window expand
class Solution {
public:

    int LowerBound(vector<int>& arr,int x){
        int start=0,end=arr.size()-1;
        int ans=-1;

        while(start<=end){
            int mid=start+(end-start)/2;

            if(arr[mid]>=x){
                ans=mid;
                end=mid-1;
            }
            else if(x > arr[mid]){
                start=mid-1;
            }
            else{
                end=mid-1;
            }
        }
        return ans;
    }

    vector<int> bs_method(vector<int>& arr, int k, int x){
        int h=LowerBound(arr,x);
        int l=h-1;

        while(k--){
            if(x-arr[l] > arr[h]-x){
                h++;
            }
            else{
                l--;
            }
        }
        return vector<int> (arr.begin()+l+1,arr.begin()+h+1);
    }

    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l=0;
        int h=arr.size()-1;
        vector<int> ans;
        while(h-l>=k){
            if(x-arr[l] > arr[h]-x){
                l++;
            }
            else{
                h--;
            }
        }
        // for(int i=l;i<=h;i++){
        //     ans.push_back(arr[i]);
        // }
        return vector<int> (arr.begin()+l,arr.begin()+h+1);//last wala use nahi hota is ilye h+1
    }
};


//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//sliding window shrink
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l=0;
        int h=arr.size()-1;
        vector<int> ans;
        while(h-l>=k){
            if(x-arr[l] > arr[h]-x){
                l++;
            }
            else{
                h--;
            }
        }
        for(int i=l;i<=h;i++){
            ans.push_back(arr[i]);
        }
        return ans;
    }
};
