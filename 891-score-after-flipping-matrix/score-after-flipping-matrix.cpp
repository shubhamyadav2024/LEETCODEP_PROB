class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
       int ro=grid.size();
       int co=grid[0].size();
       for(int i=0;i<ro;i++){
            if(grid[i][0]==0){
             for(int j=0;j<co;j++){
                if(grid[i][j]==0) grid[i][j]=1;
                else grid[i][j]=0;

              }
           }
       }
       for(int j=0;j<co;j++){
        int noz=0;
        int noo=0;
        for(int i=0;i<ro;i++){
            if(grid[i][j]==0) noz++;
            else noo++;
        }
        if(noz>noo){
            for(int i=0;i<ro;i++){
                if(grid[i][j]==0) grid[i][j]=1;
                else grid[i][j]=0;
            }
        }
       } 
       int sum=0;
       for(int i=0;i<ro;i++){
        int x =1;
        for(int j=co-1;j>=0;j--){
            sum+= grid[i][j]*x;
            x *=2;
        }
       }
       return sum;
    }
};