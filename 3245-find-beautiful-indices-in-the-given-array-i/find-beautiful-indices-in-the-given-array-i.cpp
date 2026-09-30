class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {

        vector<int> ans;
        vector<int> A;
        vector<int> B;

        // Find all positions of a
        for(int i = 0; i + a.size() <= s.size(); i++) {
            if(s.substr(i, a.size()) == a) {
                A.push_back(i);
            }
        }

        // Find all positions of b
        for(int i = 0; i + b.size() <= s.size(); i++) {
            if(s.substr(i, b.size()) == b) {
                B.push_back(i);
            }
        }

        // Check each position of a
        for(int i : A) {

            for(int j : B) {

                if(abs(i - j) <= k) {
                    ans.push_back(i);
                    break;
                }

                if(j > i + k) {
                    break;
                }
            }
        }

        return ans;
    }
};