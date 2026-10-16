
class Solution {
public:
    int nextGreaterElement(int n) {
        string d = to_string(n);
        int len = d.size();
        int i = len - 2;

        
        while (i >= 0 && d[i] >= d[i + 1]) i--;
        if (i < 0) return -1;

       
        int j = len - 1;
        while (d[j] <= d[i]) j--;

        
        swap(d[i], d[j]);
        reverse(d.begin() + i + 1, d.end());

       
        long long res = stoll(d);
        return res <= INT_MAX ? (int)res : -1;
    }
};