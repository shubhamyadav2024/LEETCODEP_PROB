class Solution {
public:
    int specialArray(vector<int>& nums) {
      int n=nums.size();
      sort(nums.begin(),nums.end());
      if(nums[0]>=n) return n;
      for(int i=1;i<n;i++){
        int len =n-i;
        if(nums[i]==nums[i-1]) continue;
        if(nums[i]>=len && len >nums[i-1]) return len;
      }  
      return -1;
    }
};