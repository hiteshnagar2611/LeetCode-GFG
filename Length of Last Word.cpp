class Solution {
public:
    int lengthOfLastWord(string s) {
        int i=s.size()-1;
        int count=0;
        int flag=0;

        while(i>=0){
            if(s[i]==' ' && flag){
                break;
            }
            if(s[i]!=' '){
                flag=1;
                count++;
            }
            i--;
        }
        return count;

    }
};
