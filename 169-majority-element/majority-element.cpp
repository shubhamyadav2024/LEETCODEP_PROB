class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count =0;
        int condidate=0;
        for(int num:nums){
            if(count==0){
                condidate=num;
            }
            if(num==condidate){
                count+=1;

            }
            else{
                count -=1;

            }
        }
        return condidate;
    }
};