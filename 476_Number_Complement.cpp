class Solution {
public:
    int findComplement(int num) {
        vector<int> v;
        while(num!=0)               // to convert no. to binary
        {
            v.push_back(num%2);
            num=num/2;
        }

        for(int i=0;i<v.size();i++)    //to change all 1's to 0 and 0's to 1
        {
            if(v[i]==0)
            v[i]=1;
            else
            v[i]=0;
        }
        long int s=1;
        for(int i=0;i<v.size();i++)    //to convert binary to number
        { 
            num=num + v[i] * s;
            s = s * 2;   
        } 
    return num;       
    }
};
