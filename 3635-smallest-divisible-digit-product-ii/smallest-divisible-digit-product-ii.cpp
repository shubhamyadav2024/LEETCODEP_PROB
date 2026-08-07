#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    string getMinDigits(int c2, int c3, int c5, int c7) {
        int d9 = c3 / 2; c3 %= 2;
        int d8 = c2 / 3; c2 %= 3;
        
        int d6 = 0;
        if (c3 == 1 && c2 > 0) {
            d6 = 1;
            c3 = 0;
            c2 -= 1;
        }
        
        int d4 = c2 / 2; c2 %= 2;
        
        string res = "";
        res.append(c2, '2');
        res.append(c3, '3');
        res.append(d4, '4');
        res.append(c5, '5');
        res.append(d6, '6');
        res.append(c7, '7');
        res.append(d8, '8');
        res.append(d9, '9');
        return res;
    }

    vector<int> getFactors(char c) {
        int d = c - '0';
        int f2 = 0, f3 = 0, f5 = 0, f7 = 0;
        while (d > 0 && d % 2 == 0) { f2++; d /= 2; }
        while (d > 0 && d % 3 == 0) { f3++; d /= 3; }
        if (c == '5') f5 = 1;
        if (c == '7') f7 = 1;
        return {f2, f3, f5, f7};
    }

public:
    string smallestNumber(string num, long long t) {
        int req2 = 0, req3 = 0, req5 = 0, req7 = 0;
        long long temp = t;
        
        while (temp % 2 == 0) { req2++; temp /= 2; }
        while (temp % 3 == 0) { req3++; temp /= 3; }
        while (temp % 5 == 0) { req5++; temp /= 5; }
        while (temp % 7 == 0) { req7++; temp /= 7; }
        
        if (temp > 1) return "-1";

        int n = num.length();
        vector<int> pref2(n + 1, 0), pref3(n + 1, 0), pref5(n + 1, 0), pref7(n + 1, 0);
        int first_zero = -1;
        
        for (int i = 0; i < n; i++) {
            if (num[i] == '0' && first_zero == -1) {
                first_zero = i;
            }
            vector<int> f = getFactors(num[i]);
            pref2[i + 1] = pref2[i] + f[0];
            pref3[i + 1] = pref3[i] + f[1];
            pref5[i + 1] = pref5[i] + f[2];
            pref7[i + 1] = pref7[i] + f[3];
        }

        if (first_zero == -1 && pref2[n] >= req2 && pref3[n] >= req3 && pref5[n] >= req5 && pref7[n] >= req7) {
            return num;
        }

        int limit = (first_zero == -1) ? n - 1 : first_zero;
        
        for (int i = limit; i >= 0; i--) {
            int cur2 = pref2[i], cur3 = pref3[i], cur5 = pref5[i], cur7 = pref7[i];
            int start_digit = (i < n) ? (num[i] - '0' + 1) : 1;
            
            for (int d = start_digit; d <= 9; d++) {
                vector<int> f = getFactors(d + '0');
                int rem2 = max(0, req2 - cur2 - f[0]);
                int rem3 = max(0, req3 - cur3 - f[1]);
                int rem5 = max(0, req5 - cur5 - f[2]);
                int rem7 = max(0, req7 - cur7 - f[3]);

                string min_digits = getMinDigits(rem2, rem3, rem5, rem7);
                int rem_len = n - 1 - i;

                if ((int)min_digits.length() <= rem_len) {
                    string ans = num.substr(0, i);
                    ans += to_string(d);
                    ans.append(rem_len - min_digits.length(), '1');
                    ans += min_digits;
                    return ans;
                }
            }
        }

        string min_digits = getMinDigits(req2, req3, req5, req7);
        int target_len = max(n + 1, (int)min_digits.length());
        
        string ans = "";
        ans.append(target_len - min_digits.length(), '1');
        ans += min_digits;
        return ans;
    }
};