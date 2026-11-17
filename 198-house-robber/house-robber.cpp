class Solution {
public:
    vector<int> dp;

    int ft(vector<int>& arr, int i) {
        if (i >= arr.size()) return 0;

        if (dp[i] != -1) return dp[i];

        int pick = arr[i] + ft(arr, i + 2);
        int notPick = ft(arr, i + 1);

        return dp[i] = max(pick, notPick);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        dp.assign(n, -1);

        return ft(nums, 0);
    }
};