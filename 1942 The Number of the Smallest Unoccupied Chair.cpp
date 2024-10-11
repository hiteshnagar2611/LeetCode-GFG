class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        vector<pair<int,pair<int,int>>> a;
        int n=times.size();

        for(int i=0;i<n;i++){
            pair<int,pair<int,int>> p={times[i][0],{times[i][1],i}};
            a.push_back(p);
        }
        sort(a.begin(),a.end());
        vector<int> chair(n,-1);
        for(int i=0;i<n;i++){
            int arr=a[i].first;
            int dep=a[i].second.first;
            int fri=a[i].second.second;

            for(int j=0;j<n;j++){
                if(chair[j]<=arr){
                    chair[j]=dep;
                    if(fri==targetFriend){
                        return j;
                    }break;
                }
            }
        }return 0;

    }
};
