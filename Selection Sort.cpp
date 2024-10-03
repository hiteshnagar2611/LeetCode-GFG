class Solution
{
    public:
    int select(int arr[], int i, int n)
    {
        // code here such that selectionSort() sorts arr[]
        int min = arr[i];
        int x=i;
        for(int j=i+1; j<n; j++){
            if(min > arr[j]){
                    min= arr[j];
                    x=j;
                }
        }
        
        return x;
    }
     
    void selectionSort(int arr[], int n)
    {
       //code here
       for(int i=0; i< n-1; i++){
            int a = select(arr, i, n);
            swap(arr[i], arr[a]);
        }
        
    }
};
