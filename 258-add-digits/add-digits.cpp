class Solution {
public:

    int addDigits(int num) {
         int count =0;
         int n=num;
         while(n >= 10){
         count=0;
         
    while(n!=0){
        int digit = n%10;
        count += digit;
        n=n/10;
    }
    n =count;
    }
    return n;
    }
};