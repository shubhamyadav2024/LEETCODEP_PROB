class Solution {
public:
  int sum(vector<int>& arr, int mid){
    int n = arr.size();
    int sum =0;
    int count =1;
    for(int i =0;i<n;i++){
          if( arr[i] > mid ){
          return INT_MAX;
          }
                if(sum+arr[i]> mid) {;
                count++;
                sum = arr[i];
                }
                else sum += arr[i];
            }
    
          return count;
    }
  
    int splitArray(vector<int>& arr, int k) {
       int n = arr.size();
    
      int lo = *max_element(arr.begin(),arr.end());
      int hi = accumulate(arr.begin(),arr.end(),0);
      int ans =hi;
      while(lo<=hi){
        int mid= lo +(hi-lo)/2;
        if(sum(arr,mid)<=k){
            ans = mid;
            hi=mid-1;
        }
        else lo = mid+1;
      }
      return ans;
    }
};