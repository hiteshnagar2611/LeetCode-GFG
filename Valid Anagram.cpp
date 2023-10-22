class Solution {
public:
    bool isAnagram(string s, string t) {
        int firqTable[256]={0};

        for(int i=0;i<s.size();i++){
            firqTable[s[i]]++;
        }
        for(int j=0;j<t.size();j++){
            firqTable[t[j]]--;
        }

        for(int k=0;k<256;k++){
            if(firqTable[k] != 0){
                return false;
            }
        }
        return true;
    }
};
