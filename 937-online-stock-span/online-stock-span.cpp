class StockSpanner {
public:
    stack<pair<int, int>> st;
    int idx = 0;

    StockSpanner() {
    }

    int next(int price) {
        while (!st.empty() && st.top().first <= price) {
            st.pop();
        }

        int pgi;

        if (st.empty())
            pgi = -1;
        else
            pgi = st.top().second;

        st.push({price, idx});

        int span = idx - pgi;
        idx++;

        return span;
    }
};