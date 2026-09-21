class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
       int n = candies.size();
       vector<bool> ans;
       int Cmax= 0;
       for(int i =0;i<n;i++){
        Cmax= max(Cmax, candies[i]);
       }
       for(int i=0;i<n;i++){
        if(candies[i] + extraCandies >= Cmax){
         ans.push_back(true);
        }
        else ans.push_back(false);
       }
    
       return ans; 
    }
};