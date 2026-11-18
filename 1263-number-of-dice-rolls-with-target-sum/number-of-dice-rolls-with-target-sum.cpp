#define ll long long int
#define  mod 1000000007
class Solution {
public:
vector<vector<ll>> dp;
int f(int n ,int k ,int t){
    if(n ==0 && t==0)return 1;
  if(n == 0 || t < 0) return 0;
    if(dp[n][t] !=-1) return dp[n][t];
    ll sum =0;
    for(int i =1;i<=k;i++){
        if(t-i<0) break;
       sum = ((sum + f(n-1, k, t-i) % mod)%mod);
    }
    return dp[n][t] = sum%mod;
}
    int numRollsToTarget(int n, int k, int target) {
          dp.assign(n+1, vector<ll>(target+1, -1));
       return  f(n,k,target);
    }
};