class Solution {
public:
    static constexpr int MOD = 1e9 + 7;

    int n, mx;
    vector<int> nums;
    vector<vector<vector<int>>> memo;

    int dfs(int i, int g1, int g2) {
        if (i == n)
            return (g1 && g1 == g2);

        int &res = memo[i][g1][g2];
        if (res != -1)
            return res;

        res = dfs(i + 1, g1, g2);

        int ng1 = (g1 == 0 ? nums[i] : gcd(g1, nums[i]));
        res = (res + dfs(i + 1, ng1, g2)) % MOD;

        int ng2 = (g2 == 0 ? nums[i] : gcd(g2, nums[i]));
        res = (res + dfs(i + 1, g1, ng2)) % MOD;

        return res;
    }

    int subsequencePairCount(vector<int>& nums) {
        this->nums = nums;
        n = nums.size();
        mx = *max_element(nums.begin(), nums.end());

        memo.assign(n,
            vector<vector<int>>(mx + 1,
                vector<int>(mx + 1, -1)));

        return dfs(0, 0, 0);
    }
};