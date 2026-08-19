class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      int ro=matrix.size();
      int co =matrix[0].size();
      int i=0;
      int j=co-1;
      while(i<ro && j>=0){
        if(matrix[i][j]==target) return true;
        else if(matrix[i][j]>target){
            j--;
        }
        else 
            i++;
        
      }  
      return false;
    }
};