class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
       int total=0;
       for(int x :nums){
        total =(total +x)%p;
        
       } 
        int rem = total;
        if(rem==0) return 0;
        unordered_map<int,int>mp;
        mp[0]=-1;
        int prefix=0;
        int ans=nums.size();
        for(int i=0;i<nums.size();i++){
            prefix=(prefix+nums[i])%p;
            int required= (prefix-rem+p)%p;
            if(mp.find(required)!=mp.end()){
                ans=min(ans,i-mp[required]);
            }
                mp[prefix]=i;
        }
        return ans==nums.size()?-1:ans;
    }
};