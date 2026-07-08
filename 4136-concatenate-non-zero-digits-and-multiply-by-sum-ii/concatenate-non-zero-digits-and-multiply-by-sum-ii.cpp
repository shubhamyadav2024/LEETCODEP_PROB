

class Solution {
public:
    static const int MOD = 1e9 + 7;

    struct Node {
        long long num;
        long long sum;
        int len;
        Node(long long n = 0, long long s = 0, int l = 0)
            : num(n), sum(s), len(l) {}
    };

    vector<Node> seg;
    vector<long long> pow10;

    Node merge(Node a, Node b) {
        Node res;
        res.len = a.len + b.len;
        res.sum = a.sum + b.sum;
        res.num = (a.num * pow10[b.len] + b.num) % MOD;
        return res;
    }

    void build(int idx, int l, int r, string &s) {
        if (l == r) {
            if (s[l] == '0')
                seg[idx] = Node(0, 0, 0);
            else {
                int d = s[l] - '0';
                seg[idx] = Node(d, d, 1);
            }
            return;
        }

        int mid = (l + r) / 2;
        build(2 * idx, l, mid, s);
        build(2 * idx + 1, mid + 1, r, s);
        seg[idx] = merge(seg[2 * idx], seg[2 * idx + 1]);
    }

    Node query(int idx, int l, int r, int ql, int qr) {
        if (qr < l || r < ql)
            return Node();

        if (ql <= l && r <= qr)
            return seg[idx];

        int mid = (l + r) / 2;
        Node left = query(2 * idx, l, mid, ql, qr);
        Node right = query(2 * idx + 1, mid + 1, r, ql, qr);

        return merge(left, right);
    }

    vector<int>  sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();

        pow10.assign(n + 1, 1);
        for (int i = 1; i <= n; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;

        seg.assign(4 * n, Node());
        build(1, 0, n - 1, s);

        vector<int> ans;

        for (auto &q : queries) {
            Node cur = query(1, 0, n - 1, q[0], q[1]);
            ans.push_back((cur.num * cur.sum) % MOD);
        }

        return ans;
    }
};