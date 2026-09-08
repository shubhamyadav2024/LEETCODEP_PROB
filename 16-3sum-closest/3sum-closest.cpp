class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
       int n=nums.size();
       int close= nums[0]+nums[1]+nums[2];
       //sort(nums.begin(),nums.end());
       for(int i=0;i<n-2;i++){
        for(int j=i+1;j<n-1;j++){
            for(int k=j+1;k<n;k++){
              int sum =  nums[i]+nums[j]+nums[k]; 
              if(abs(sum-target)< abs(close-target)){
                close=sum;
              }
            }
        }
       }
       return close;
    }
};