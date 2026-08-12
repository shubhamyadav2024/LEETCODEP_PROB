class Solution {
public:
double pow(double x, int n ){
    long long m=n;
    double ans =1;
    if(m<0){
    m =-m;

    }
    while(m>0){
        if(m%2 ==1){
            ans = ans * x;
            m = m-1;
        }
        else {
            m = m/2;
            x = x*x;
        }

    }
    if(n<0) return 1/ans;
    else{
        return ans;
    }
}
    double myPow(double x, int n) {
        return pow(x,n);
    }
};