class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        int n = arr.size();
        int count=0;
        int sum =0;
       unordered_map<int,int>mp;
        mp[0]=1;
       for(int i =0;i<n;i++){
        sum += arr[i];
        int rem = sum -k;
        if(mp.find(rem)!=mp.end()){
        count +=mp[rem];
       
        }
        mp[sum]++;
        }
return count;
    }
};