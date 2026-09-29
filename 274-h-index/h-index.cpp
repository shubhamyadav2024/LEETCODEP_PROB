class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        sort(citations.begin(),citations.end());
        for(int i =0;i<n;i++){
          int  paper = n-i;
            if(paper  <= citations[i]) return paper;
        }
        return {};
    }
};