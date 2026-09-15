class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int k = minutes;
        
        int maxloss= INT_MIN;
        int preloss =0;
        // vector<int> arr = &customers;
        int n= customers.size();
        for(int i=0;i<k;i++){
           if(grumpy[i]==1)  preloss += customers[i];
           maxloss = preloss;
           
        }
          int maxidx =0;
        int i =1;
        int j =k;
        while(j<n){
            
          int currloss = preloss;
           if(grumpy[j]==1) currloss += customers[j];  
           if(grumpy[i-1]==1) currloss -= customers[i-1];  
        
        if(maxloss < currloss){
            maxloss = currloss;
            maxidx =i;
        }
        preloss = currloss;
        i++;
        j++;
        }
        for(int i= maxidx;i<maxidx+k;i++){
            grumpy[i]=0;
        }
        int sum =0;
        for(int i=0;i<n;i++){
            if(grumpy[i]==0) sum += customers[i];
        }
        return sum;
    }
};