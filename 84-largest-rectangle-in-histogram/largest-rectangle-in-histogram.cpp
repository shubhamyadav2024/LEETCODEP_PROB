
class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();
        vector<int> nsi(n), psi(n);
        
        stack<int> st;

        // Next Smaller Index (NSI)
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            if(st.empty()) nsi[i] = n;
            else nsi[i] = st.top();

            st.push(i);
        }

        while(!st.empty()) st.pop();

        // Previous Smaller Index (PSI)
        for(int i = 0; i < n; i++) {
            while(!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            if(st.empty()) psi[i] = -1;
            else psi[i] = st.top();

            st.push(i);
        }

        // Calculate maximum area
        int maxarea = 0;

        for(int i = 0; i < n; i++) {
            int height = arr[i];
            int breadth = nsi[i] - psi[i] - 1;
            int area = height * breadth;
            
            maxarea = max(maxarea, area);
        }

        return maxarea;
    }
};
