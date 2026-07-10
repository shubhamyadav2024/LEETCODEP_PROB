class Solution {
public:
    static const int MOD = 1e9 + 7;
    vector<vector<int>> dp;
    vector<int> powers;

    int solve(int idx, int rem) {
        if (rem == 0) return 1;
        if (idx == powers.size() || rem < 0) return 0;

        if (dp[idx][rem] != -1)
            return dp[idx][rem];

        long long take = solve(idx + 1, rem - powers[idx]);
        long long skip = solve(idx + 1, rem);

        return dp[idx][rem] = (take + skip) % MOD;
    }

    int numberOfWays(int n, int x) {
        powers.clear();

        for (long long i = 1;; i++) {
            long long val = 1;
            for (int j = 0; j < x; j++)
                val *= i;

            if (val > n) break;
            powers.push_back((int)val);
        }

        dp.assign(powers.size(), vector<int>(n + 1, -1));

        return solve(0, n);
    }
};