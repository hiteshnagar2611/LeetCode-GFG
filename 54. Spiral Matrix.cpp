class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;

        int m=matrix.size();
        int n=matrix[0].size();

        int total_elements= m*n;

        int startingrow=0;
        int endingrow=m-1;
        int startingcol=0;
        int endingcol=n-1;

        int count=0;

        while(count < total_elements){
            //left to right
            for(int i=startingcol;i<=endingcol && count<total_elements;i++){
                ans.push_back(matrix[startingrow][i]);
                count++;
            }
            startingrow++;

            //up to down
            for(int i=startingrow;i<=endingrow && count<total_elements;i++){
                ans.push_back(matrix[i][endingcol]);
                count++;
            }
            endingcol--;

            //right to left
            for(int i=endingcol;i>=startingcol && count<total_elements;i--){
                ans.push_back(matrix[endingrow][i]);
                count++;
            }
            endingrow--;

            //down to up
            for(int i=endingrow;i>=startingrow && count<total_elements;i--){
                ans.push_back(matrix[i][startingcol]);
                count++;
            }
            startingcol++;

        }

        return ans;



    }
};
