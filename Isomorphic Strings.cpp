class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int hash[256] = {0};
        bool thash[256] = {0};

        if(s.size() != t.size()){
            return false;
        }

        for (int i = 0; i < s.size(); i++) {
            if (hash[s[i]] == 0 && thash[t[i]]==0) {
                hash[s[i]] = t[i];
                thash[t[i]] = true;
            }
        }

        for (int j = 0; j < s.size(); j++) {
            if (char(hash[s[j]]) != t[j]) {
                return false;
            }
        }

        return true;
    }
};
