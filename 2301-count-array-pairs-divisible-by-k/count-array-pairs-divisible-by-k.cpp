
class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
        unordered_map<int, long long> mp;
        long long ans = 0;

        for (int x : nums) {
            int g = gcd(x, k);

            for (auto &[g2, cnt] : mp) {
                if ((1LL * g * g2) % k == 0)
                    ans += cnt;
            }

            mp[g]++;
        }

        return ans;
    }
};