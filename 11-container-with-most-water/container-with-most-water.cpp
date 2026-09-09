class Solution {
public:
    int maxArea(vector<int>& height) {
      int n=height.size();
      int maxwater =0;
      int l=0;
      int r=n-1;
     

      while(l<r){
        
          int minimum = min(height[l],height[r]);
          int  area = minimum * (r-l);
            maxwater= max(maxwater,area);
            if(height[l]<height[r]){
                l++;
            }
            else{
             r--;
            }
      }  
      return maxwater;
    }
};