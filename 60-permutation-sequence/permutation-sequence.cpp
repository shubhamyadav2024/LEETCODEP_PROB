class Solution {
public:
    string getPermutation(int n, int k) {
        string ans = "";

        vector<int> nums;

        for (int i = 1; i <= n; i++) {
            nums.push_back(i);
        }

        int fact = 1;

        for (int i = 1; i < n; i++) {
            fact *= i;
        }

        k--; 
        while (!nums.empty()) {
            int idx = k / fact;

            ans += to_string(nums[idx]);

            nums.erase(nums.begin() + idx);

            if (nums.empty()) {
                break;
            }

            k = k % fact;

            fact = fact / nums.size();
        }

        return ans;
    }
};