class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n,vector<int>(n));
        // int n =matrix.size();
        // int n =matrix[0].size();
        int minr =0;
        int minc =0;
        int maxr=n-1;
        int maxc=n-1;
        int num=1;
        while(minr<=maxr && minc<=maxc){
            //right
            for(int j=minc;j<=maxc;j++){
                ans[minr][j]= num++;
            }
            minr++;
            for(int i=minr;i<=maxr;i++){
                ans[i][maxc]=num++;

            }
            maxc--;
            for(int j =maxc;j>=minc;j--){
                ans[maxr][j]=num++;
            }
            maxr--;
            for(int i=maxr;i>=minr;i--){
                ans[i][minc]=num++;
            }
            minc++;
        }
        return ans;
    }
};