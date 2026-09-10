class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int n =nums.size();
        int count=0;
        for(int i=0;i<n;i++){
         int ans =0;
            int res = nums[i];
            while(res !=0){
           res = res/10;
           ans++;
            
            }
            if(ans%2==0) count++;
        }
        return count;
    }
};