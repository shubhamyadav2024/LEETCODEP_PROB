class Solution {
public:
    int countOdds(int low, int high) {
        int count =0;
        int i =low;
      while(i<=high){
        if(i%2!=0) count++;
       i++;
       } 
       return count;
    }
};