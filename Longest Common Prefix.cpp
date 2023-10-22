class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int first=0;
        int last=strs.size()-1;
        int i=0;
        string s;

        sort(strs.begin(),strs.end());
        while(i<strs[first].size()){
            if(strs[first][i]==strs[last][i]){
                s.push_back(strs[first][i]);
            }
            else{
                break;
            }
            i++;
        }
        return s;
    }
};
