class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> ans;
        ans = arr;

        sort(ans.begin(),ans.end());
        unordered_map<int,int>mp;

        int i=0, n=ans.size(), rank=1;

        while(i<n){
            if(i==0){

            }
            else if(ans[i] == ans[i-1]){

            }
            else{
                rank++;
            }
            mp[ans[i]] = rank;
            i++;
        }

        for(auto &x:arr){
            x=mp[x];
        }

        return arr;
    }
};
