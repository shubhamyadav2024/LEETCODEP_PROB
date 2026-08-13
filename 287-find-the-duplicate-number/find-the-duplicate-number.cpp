class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n= nums.size();
        int low =0;
        int high = n-1;
        while(low<high){
            int mid = low+(high-low)/2;
        int count =0;
       for(int x : nums){
        if(x<=mid){
            count++;
           
        }
       }
      if(count>mid){
        high=mid;
      }
      else {
        low = mid +1;
      }
        }
        return low;
    }
};