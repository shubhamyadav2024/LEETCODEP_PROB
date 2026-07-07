class Solution {
public:
    int solve(vector<int>& v, int i, int j) {
        
        if (i + 1 >= j) {
            return 0;
        }

        int ans = INT_MAX;
        
        for (int k = i + 1; k < j; k++) {
            int current_triangle_score = v[i] * v[j] * v[k];
            
            
            ans = min(ans, current_triangle_score + solve(v, i, k) + solve(v, k, j));
        }
        
        return ans;
    }
    int solvemm(vector<int>& v, int i, int j,vector<vector<int>> &dp) {
        
        if (i + 1 >= j) {
            return 0;
        }
        if(dp[i][j] != -1) return dp[i][j];

        int ans = INT_MAX;
        
        for (int k = i + 1; k < j; k++) {
            int current_triangle_score = v[i] * v[j] * v[k];
            
            ans = min(ans, current_triangle_score + solvemm(v, i, k,dp) + solvemm(v, k, j,dp));
        }
            dp[i][j] = ans;
        
        return dp[i][j];
    }

    int minScoreTriangulation(vector<int>& values) {
    int n = values.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solvemm(values,0,n-1,dp);
    }
};