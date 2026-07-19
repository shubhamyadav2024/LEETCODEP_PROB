class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        int i = 0;

        while (i + 1 < n) {
            while (i + 1 < n && arr[i] == arr[i + 1]) i++;

            int up = 0, down = 0;

            while (i + 1 < n && arr[i] < arr[i + 1]) {
                up++;
                i++;
            }

            while (i + 1 < n && arr[i] > arr[i + 1]) {
                down++;
                i++;
            }

            if (up > 0 && down > 0) {
                ans = max(ans, up + down + 1);
            }
        }

        return ans;
    }
};