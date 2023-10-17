class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> menits;
        
        for(int i=0;i<timePoints.size();i++){
            string curr = timePoints[i];

            int hour= stoi( curr.substr(0,2));
            int minit= stoi( curr.substr(3,5));
            int totalmin = hour * 60 + minit ;

            menits.push_back(totalmin);
        }

        sort(menits.begin(),menits.end());

        int ans=INT_MAX;
        int diff;
        for(int j=0;j<menits.size()-1;j++){
            diff= menits[j+1] - menits[j];
            ans= min(ans, diff);
        }

        diff= menits[0]+1440 - menits[menits.size()-1];
        ans= min(ans, diff);
        return ans;
    }
};
