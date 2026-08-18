class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n =nums.size();
        mp[0]=-1;
        int count=0;
        int ans=0;
        for(int i=0;i<n;i++){
            
        if(nums[i]==0){
            count--;
        }
        else{
            count++;
        }
        if(mp.find(count)!=mp.end()){
             ans = max(ans, i - mp[count]);
        }
        else{
            mp[count]=i;
        }
        }
        return ans;
    }
};