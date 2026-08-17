class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int longest =1;
        int curr=1;
       if(n==0) return 0;
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]){
                continue;
            }
            if(nums[i]==nums[i-1]+1){
                curr++ ;
            }
            else {
                curr =1;

            }
            longest= max(longest,curr);
        }
        return longest;
    }
};