class Solution {
public:
bool check(int mid,vector<int>& wt,int days){
    int n = wt.size();
    int m =mid;
    int count=1;
    for(int i=0;i<n;i++){
        if(m>=wt[i]){
            m-=wt[i];
        }
        else
        { count++;
        m=mid;
        m-=wt[i];
    }
    }
    if(count>days) return false;
    else return true;
}
    int shipWithinDays(vector<int>& wt, int days) {
     int n= wt.size();
     int max =INT_MIN;
     int sum=0;
     for(int i=0;i<n;i++){
        if(max<wt[i]) max=wt[i];
        sum +=wt[i];
     } 
     int lo=max;
     int hi=sum;
     int minCap=sum;
     while(lo<=hi){
        int mid =lo+(hi-lo)/2;
        if(check(mid,wt,days)){
            minCap=mid;
            hi=mid-1;
        }
        else lo=mid+1;
     }
     return minCap;
        }
};