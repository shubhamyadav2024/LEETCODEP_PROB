class Solution {
public:
int solve(vector<int>& abstacle ,int curr,int currp){
    int n = abstacle.size()-1;
  if(currp==n) return 0;
  if(abstacle[currp+1] != curr) return solve(abstacle,curr,currp+1);
  else {
    int ans = INT_MAX;
    for(int i= 1;i<=3;i++){
        if(curr !=i && abstacle[currp] !=i)
        ans = min(ans,1+solve(abstacle,i,currp));
    }
    return ans;
  }
}
int solvem(vector<int>& abstacle ,int curr,int currp, vector<vector<int>>& dp){
    int n = abstacle.size()-1;
  if(currp==n) return 0;
  if(dp[curr][currp]!=-1) return dp[curr][currp];
  if(abstacle[currp+1] != curr) return solvem(abstacle,curr,currp+1,dp);
  else {
    int ans = INT_MAX;
    for(int i= 1;i<=3;i++){
        if(curr !=i && abstacle[currp] !=i)
        ans = min(ans,1+solvem(abstacle,i,currp,dp));
    }
    dp[curr][currp] =ans;
    return dp[curr][currp];
  }
}
    int minSideJumps(vector<int>& abstacles) {
        vector<vector<int>> dp(4,vector<int>(abstacles.size(),-1));
        return solvem(abstacles,2,0,dp);
    }
};