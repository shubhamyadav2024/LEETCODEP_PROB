class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {

        vector<int> order(n), pos(n), arr(n);

        iota(order.begin(), order.end(), 0);

        sort(order.begin(), order.end(), [&](int a, int b) {
            return nums[a] < nums[b];
        });

        for (int i = 0; i < n; i++) {
            pos[order[i]] = i;
            arr[i] = nums[order[i]];
        }

        vector<int> nxt(n);
        int r = 0;

        for (int l = 0; l < n; l++) {
            while (r + 1 < n && arr[r + 1] - arr[l] <= maxDiff)
                r++;
            nxt[l] = r;
        }

        int LOG = 0;
        while ((1 << LOG) <= n) LOG++;

        vector<vector<int>> up(LOG, vector<int>(n));

        up[0] = nxt;

        for (int k = 1; k < LOG; k++) {
            for (int i = 0; i < n; i++) {
                up[k][i] = up[k - 1][up[k - 1][i]];
            }
        }

        vector<int> ans;

        for (auto &q : queries) {
            int a = pos[q[0]];
            int b = pos[q[1]];

            if (a > b) swap(a, b);

            if (a == b) {
                ans.push_back(0);
                continue;
            }

            int cur = a;
            int dist = 0;

            for (int k = LOG - 1; k >= 0; k--) {
                if (up[k][cur] < b) {
                    cur = up[k][cur];
                    dist += (1 << k);
                }
            }

            if (up[0][cur] >= b)
                ans.push_back(dist + 1);
            else
                ans.push_back(-1);
        }

        return ans;
    }
};