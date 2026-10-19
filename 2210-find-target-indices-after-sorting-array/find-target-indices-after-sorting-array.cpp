class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<int> ans;
     int n = nums.size();
     int lo = 0;
     int hi = n-1;
     int idx=-1;
     while(lo<=hi){
    int mid = lo +(hi-lo)/2;
      if(nums[mid]==target){
        idx= mid;
        hi= mid-1;
      }
      if(nums[mid]<target) lo= mid+1;
      else hi= mid-1;
     }
     if( idx !=-1){ 
     while(idx<n && nums[idx]==target){
        ans.push_back(idx);
        idx++;
     }
     }  
     return ans;
    }
};