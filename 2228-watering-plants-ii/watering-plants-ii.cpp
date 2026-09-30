class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int n = plants.size();
        int l=0;
        int r=n-1;
        int count =0;
        int waterA=capacityA;
        int waterB=capacityB;
        while(l<r){
            if(waterA >= plants[l] ){
                waterA -= plants[l] ;
                l++;
            }
            else{
                count++;
                waterA = capacityA;
                waterA -= plants[l] ;
                l++;
        }
          if(waterB>=plants[r]) {
               waterB -= plants[r];
               r--; 
            }
            else {
                count++;
                waterB = capacityB;
                waterB -= plants[r];
                r--;
            }
        }
        if(l==r){
          if(waterA < plants[l] && waterB < plants[r]){
            count++;
          }
        }
        return count;
    }
};