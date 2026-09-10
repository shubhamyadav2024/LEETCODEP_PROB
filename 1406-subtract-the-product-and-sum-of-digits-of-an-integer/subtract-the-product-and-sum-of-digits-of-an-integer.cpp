class Solution {
public:
    int subtractProductAndSum(int n) {
        int pro=1;
        int sum=0;
        while(n>0){
            int digit=n%10;
            pro *= digit;
           n= n/10;
           sum +=digit;
        }
        return pro-sum;
    }
};