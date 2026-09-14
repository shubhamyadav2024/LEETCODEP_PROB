class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n= numbers.size();
        int lo=0;
        int hi =n-1;
        while(lo<hi){
            if(numbers[lo]+numbers[hi]==target) {
                return {lo+1,hi+1};
            // lo++;
            // hi--;
            

            }
            if(numbers[lo]+numbers[hi]> target) hi--;
        else lo++;
        }
        return {-1,-1};
    }
};