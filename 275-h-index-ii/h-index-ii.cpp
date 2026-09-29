class Solution {
public:
    int hIndex(vector<int>& citations) {
       int n = citations.size();
      int lo=0;
      int hi= n-1;
      int ans =0;
      while(lo<=hi){
        int mid = lo+(hi-lo)/2;
        int paper = n-mid;
        if(paper<=citations[mid]){
            ans = paper;
            hi = mid-1;
        }
        else lo= mid+1;
      }
      return ans;
    }
};