class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
      
       int lo=0;
       int hi =nums.size()-1;
       int count=0;
       while(lo<=hi){
        if(nums[lo]==0 && nums[hi] !=0){
            swap(nums[lo],nums[hi]);
            count++;
            lo++;
            hi--;
        }
       else if(nums[lo] !=0){
            lo++;
        }
        else hi--;
       }
       return count; 
    }
};