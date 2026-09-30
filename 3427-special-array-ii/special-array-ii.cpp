class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {

        int n = nums.size();

        vector<int> prefix(n, 0);

        for (int i = 1; i < n; i++) {

            prefix[i] = prefix[i - 1];

            if (nums[i] % 2 == nums[i - 1] % 2) {
                prefix[i]++;
            }
        }

        vector<bool> ans;

        for (int i = 0; i < queries.size(); i++) {

            int from = queries[i][0];
            int to = queries[i][1];

            int badpairs = prefix[to] - prefix[from];

            if (badpairs == 0)
                ans.push_back(true);
            else
                ans.push_back(false);
        }

        return ans;
    }
};