class Solution {
public:
    bool checkpali(string s, int start, int end){
        while(start<end){
            if(s[start]==s[end]){
                start++;
                end--;
            }
            else{
                return false;
            }
            
        }
        return true;
    }

    bool validPalindrome(string s) {
        int i=0;
        int j=s.length()-1;

        while(i<j){
            if(s[i] != s[j]){
                return checkpali(s,i+1,j) || checkpali(s, i,j-1);
            }
            else{
                i++;
                j--;
            }
        }
        return true;
    }
};
