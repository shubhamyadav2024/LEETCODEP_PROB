class Solution {
public:
int sumofd(vector<int>& arr, int d){
    int sum =0;
    int n =arr.size();
    for(int i=0;i<n;i++){
        sum += ceil((double)(arr[i])/(double)(d));
    }
    return sum;
}
  
    int smallestDivisor(vector<int>& arr, int threshold) {
         int lo=1;
      int ans = -1;
      int hi= *max_element(arr.begin(),arr.end());
      while(lo<=hi){
        int mid= lo+(hi-lo)/2;
        if(sumofd(arr,mid)<=threshold){
            ans =mid;
            hi=mid-1;
        }
        else lo=mid+1;
      }  
      return lo;
    }
};