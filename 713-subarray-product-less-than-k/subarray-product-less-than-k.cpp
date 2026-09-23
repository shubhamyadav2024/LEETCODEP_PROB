class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        int i = 0;
        long long prod = 1;

        if (k <= 1) return 0;

        for (int j = 0; j < n; j++) {

            prod *= nums[j];

            while (prod >= k) {
                prod /= nums[i];
                i++;
            }

            count += j - i + 1;
        }

        return count;
    }
};