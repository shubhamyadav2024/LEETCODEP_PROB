class Solution {
public:
    bool isPerfectSquare(int num) {
       int lo=0;
       int hi = num;
       while(lo<=hi){
        int mid = lo +(hi-lo)/2;
        if(1LL*mid*mid == num) return true;
        else if(1LL*mid*mid<num) lo =mid+1;
        else hi = mid-1;
       }
       return false;
    }
};