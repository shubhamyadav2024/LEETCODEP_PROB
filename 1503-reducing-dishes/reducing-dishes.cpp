class Solution {
public:
int solve(vector<int>& satisfaction ,int idx,int t){
    if(idx==satisfaction.size()) return 0;
    int incl =  satisfaction[idx]* (t+1)+solve(satisfaction,idx+1,t+1);
    int exl = 0+ solve(satisfaction,idx+1,t);
    return max(incl,exl);
}
int solvem(vector<int>& satisfaction ,int idx,int t,vector<vector<int>>& dp){
    if(idx==satisfaction.size()) return 0;
    if(dp[idx][t]  !=-1) return dp[idx][t];
    int incl =  satisfaction[idx]* (t+1)+solvem(satisfaction,idx+1,t+1,dp);
    int exl = 0+ solvem(satisfaction,idx+1,t,dp);
    return dp[idx][t] =  max(incl,exl);
}
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
         int n =satisfaction.size();
         vector<vector<int> >dp(n+1,vector<int>(n+1,-1));

       return solvem(satisfaction,0,0,dp); 
    }
};