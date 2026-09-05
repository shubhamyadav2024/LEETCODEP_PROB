class Solution {
public:
    int maximumCount(vector<int>& nums) {
       int n=nums.size();
       int pos=0;
       int neg=0;
       int lo=0;
       int hi=n-1;
       while(lo<=hi){
        int mid =lo+(hi-lo)/2;
        if(nums[mid]<=0) lo=mid+1;
        else{
            if(mid>0 && nums[mid-1]>0) hi=mid-1;
            else{
                pos=n-mid;
                break;
            }
        }
       } 
      
         lo=0;
        hi=n-1;
       while(lo<=hi){
        int mid =lo+(hi-lo)/2;
        if(nums[mid]>=0) hi=mid-1;
        else{
            if(mid+1<n && nums[mid+1]<0) lo=mid+1;
            else{
                neg=mid+1;
                break;
            }
        }
       } 
       return max(pos,neg);
    }
};